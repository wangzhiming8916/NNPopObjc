//
//  NNPopObjc.h
//  NNPopObjc
//
//  Created by GuHaijun on 2019/10/3.
//  Copyright © 2019 GuHaiJun. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for NNPopObjc.
FOUNDATION_EXPORT double NNPopObjcVersionNumber;

//! Project version string for NNPopObjc.
FOUNDATION_EXPORT const unsigned char NNPopObjcVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <NNPopObjc/PublicHeader.h>


#define nn_pop_extension_prefix             __NNPopObjc
#define nn_pop_section_name                 __nn_pop_objc__

#define nn_extension(protocol, clazz) \
\
class NNPopObjc; \
\
nn_extension_section_(nn_pop_extension_prefix, protocol, clazz); \
\
@interface nn_extension_name_(nn_pop_extension_prefix, protocol, clazz) : clazz <protocol> \
\
@end \
\
@implementation nn_extension_name_(nn_pop_extension_prefix, protocol, clazz) \
\


#pragma mark - Tools

#define nn_pop_stringify(VALUE) \
        nn_pop_stringify_(VALUE)

#define nn_pop_concat(A, B) \
        nn_pop_concat_(A, B)

#define nn_pop_stringify_(VALUE) # VALUE
#define nn_pop_concat_(A, B) A ## B

#define nn_pop_section(section_name) __attribute((used, section("__DATA,"section_name" ")))

#define nn_extension_name_(prefix, protocol, clazz) \
        nn_pop_concat(prefix, \
        nn_pop_concat(_, \
        nn_pop_concat(protocol, \
        nn_pop_concat(_, clazz \
        )))) \

#define nn_extension_section_(prefix, protocol, clazz) \
        const char * \
        nn_pop_concat(k, nn_extension_name_(prefix, protocol, clazz)) \
        nn_pop_section(nn_pop_stringify(nn_pop_section_name)) = \
        "{ \
            \"prefix\"   : \""nn_pop_stringify(prefix)"\", \
            \"protocol\" : \""nn_pop_stringify(protocol)"\", \
            \"clazz\"    : \""nn_pop_stringify(clazz)"\", \
            \"protocol_implment_clazz\" : \""nn_pop_stringify(nn_extension_name_(prefix, protocol, clazz))"\" \
        }"; \

@interface NNPopObjc : NSObject

@end
