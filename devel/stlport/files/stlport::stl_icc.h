// STLport configuration file
// It is internal STLport header - DO NOT include it directly
// A list of Intel compiler for Linux portion of STLport settings.

# define _STLP_LONG_LONG long long

// Edit relative path below (or put full path) to get native
// compiler headers included. Default is "../include".
// C headers may reside in different directory, so separate macro is provided.
# if (__INTEL_COMPILER >= 800)

# define _STLP_NATIVE_INCLUDE_PATH ../include/c++
# define _STLP_NATIVE_C_INCLUDE_PATH ../include
//# define _STLP_NATIVE_CPP_C_INCLUDE_PATH ../include

# ifndef __GNUC__ 
//  If GCC compatability is disabled (-no-gcc is specified) STD needs to be redefined.
# define _STLP_REDEFINE_STD 1
# endif /* __GNUC__ */

//#define _STLP_HAS_NO_NEW_C_HEADERS 1

# endif /* __INTEL_COMPILER >= 800 */

#ifndef __FreeBSD__ // FreeBSD system headers use unsupported GCC extensions.
# ifndef __GNUC__ 
# define __GNUC__ 3
# endif
#endif

# define _STLP_NO_NATIVE_WIDE_FUNCTIONS 1

#ifdef __FreeBSD__
# include <osreldate.h>
# define _STLP_HAS_NATIVE_FLOAT_ABS
# define _STLP_NO_CSTD_FUNCTION_IMPORTS
# define _STLP_NO_LONG_DOUBLE
#endif
