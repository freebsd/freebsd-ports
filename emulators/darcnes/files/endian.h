#ifndef __HAD_MY_ENDIAN_H
#define __HAD_MY_ENDIAN_H

#include <sys/param.h>

#if (defined(BSD) && (BSD >= 199306))
/* this should filter out NetBSD, FreeBSD and OpenBSD */
#include <machine/endian.h>

#if BYTE_ORDER == BIG_ENDIAN
#define MSB_FIRST 1
#undef LSB_FIRST
#else
#define LSB_FIRST 1
#undef MSB_FIRST
#endif

#else
/* for Linux, perhaps use #ifdef __linux__? */
#include <sys/types.h>

#if defined(__BYTE_ORDER)
#if __BYTE_ORDER == __BIG_ENDIAN
#define MSB_FIRST 1
#undef LSB_FIRST
#else
#define LSB_FIRST 1
#undef MSB_FIRST
#endif /* __BYTE_ORDER == __BIG_ENDIAN */

#else /* defined(__BYTE_ORDER) */

/* not Linux, either, just set it to LSB */
#define LSB_FIRST 1
#undef MSB_FIRST

#endif /* defined(__BYTE_ORDER) */

#endif /* defined(BSD) && (BSD >= 199306) */

#endif /* __HAD_MY_ENDIAN_H */
