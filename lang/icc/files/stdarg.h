#ifndef	__INTEL_COMPILER_STDARG_H_
#define	__INTEL_COMPILER_STDARG_H_

#include_next <stdarg.h>

#if __ISO_C_VISIBLE >= 1999
/* Taken from original yvals.h. */
#ifndef va_copy
#define	va_copy(dest, src)	((dest) = (src))
#endif
#endif

#endif /* !__INTEL_COMPILER_STDARG_H_ */
