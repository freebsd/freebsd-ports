
#include_next <stdarg.h>

#if __ISO_C_VISIBLE >= 1999
/* Taken from original yvals.h. */
#ifndef va_copy
#define	va_copy(dest, src)	((dest) = (src))
#endif
#endif
