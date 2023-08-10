
#ifndef _freebsd_byteswap_h_
#define _freebsd_byteswap_h_

#include <sys/endian.h>

#define	__BYTE_ORDER	_BYTE_ORDER
#define	__BIG_ENDIAN	_BIG_ENDIAN
#define	__LITTLE_ENDIAN	_LITTLE_ENDIAN

#define bswap_16(x) bswap16 (x)
#define bswap_32(x) bswap32 (x)
#define bswap_64(x) bswap64 (x)

#endif
