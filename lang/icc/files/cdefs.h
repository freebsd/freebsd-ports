#ifndef	__INTEL_COMPILER_SYS_CDEFS_H_
#define	__INTEL_COMPILER_SYS_CDEFS_H_

#ifndef	__GNUC__
#define	__INTEL_COMPILER_NO_GNUC_DEFINED
#define	__GNUC__		3
#define	__GNUC_MINOR__		2
#define	__GNUC_PATCHLEVEL__	0
#endif

#include_next <sys/cdefs.h>

#ifdef	__INTEL_COMPILER_NO_GNUC_DEFINED
#undef	__GNUC__
#undef	__GNUC_MINOR__
#undef	__GNUC_PATCHLEVEL__
#undef	__INTEL_COMPILER_NO_GNUC_DEFINED
#endif

#endif /* !__INTEL_COMPILER_SYS_CDEFS_H_ */
