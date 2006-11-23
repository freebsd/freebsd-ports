#ifndef _FREEBSD_H_
#define _FREEBSD_H_

typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;

#define	INT64_MIN	(-0x7fffffffffffffffLL-1)
#define	UINT64_MAX	0xffffffffffffffffULL

#define	INTMAX_MIN	INT64_MIN
#define	INTMAX_MAX	INT64_MAX
#define	UINTMAX_MAX	UINT64_MAX

uintmax_t strtoumax(const char * __restrict, char ** __restrict, int);

#endif
