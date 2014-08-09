#ifndef _BYTESWAP_H
#define _BYTESWAP_H

#ifdef __OpenBSD__
#define bswap_16(x)	swap16(x)
#define bswap_32(x)	swap32(x)
#define bswap_64(x)	swap64(x)
#else
#define bswap_16(x)	bswap16(x)
#define bswap_32(x)	bswap32(x)
#define bswap_64(x)	bswap64(x)
#endif
#endif /* _BYTESWAP_H */
