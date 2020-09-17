#ifndef _OPENBSD_COMPAT_SHA1_H_
#define _OPENBSD_COMPAT_SHA1_H_

#include <sha.h>

#define SHA1_DIGEST_LENGTH		SHA_DIGEST_LENGTH
#define SHA1_DIGEST_STRING_LENGTH	(SHA1_DIGEST_LENGTH * 2 + 1)

#define SHA1_CTX	SHA_CTX
#define SHA1Init	SHA1_Init
#define SHA1Update	SHA1_Update
#define SHA1Final	SHA1_Final

#endif
