#ifndef _OPENBSD_COMPAT_SHA2_H_
#define _OPENBSD_COMPAT_SHA2_H_

#include <sha256.h>

#define SHA2_CTX	SHA256_CTX
#define SHA256Init	SHA256_Init
#define SHA256Update	SHA256_Update
#define SHA256Final	SHA256_Final

#endif
