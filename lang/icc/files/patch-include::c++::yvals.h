--- include/c++/yvals.h.orig	Thu Mar 18 20:22:51 2004
+++ include/c++/yvals.h	Sat Mar 27 13:32:51 2004
@@ -7,24 +7,6 @@
 
 _ABRCPP -- to turn ON Abridged C++ dialect (implies _ECPP)
 _ECPP -- to turn ON Embedded C++ dialect
-_NO_MT -- to turn OFF thread synchronization
-_STL_DB (or _STLP_DEBUG) -- to turn ON iterator/range debugging
-
-You can change (in this header):
-
-_COMPILER_TLS -- from 0 to 1 if _TLS_QUAL is not nil
-_EXFAIL -- from 1 to any nonzero value for EXIT_FAILURE
-_FILE_OP_LOCKS -- from 0 to 1 for file atomic locks
-_GLOBAL_LOCALE -- from 0 to 1 for shared locales instead of per-thread
-_HAS_IMMUTABLE_SETS -- from 1 to 0 to permit alterable set elements
-_HAS_STRICT_CONFORMANCE -- from 0 to 1 to disable nonconforming extensions
-_HAS_TRADITIONAL_IOSTREAMS -- from 1 to 0 to omit old iostreams functions
-_HAS_TRADITIONAL_ITERATORS -- from 1 to 0 to change vector/string iterators from
-                              just pointers to something more complicated
-_HAS_TRADITIONAL_POS_TYPE -- from 0 to 1 for streampos same as streamoff
-_HAS_TRADITIONAL_STL -- from 1 to 0 to omit old STL functions
-_IOSTREAM_OP_LOCKS -- from 0 to 1 for iostream atomic locks
-_TLS_QUAL -- from nil to compiler TLS qualifier, such as __declspec(thread)
 
 Include directories needed to compile with Dinkum C:
 
@@ -47,85 +29,10 @@
 	(--export --template_dir=lib/export)
  */
 
-#define __need___va_list
-#include <stdarg.h>
-
-#if !(defined __QNX__)
-#include <features.h>	/* Get glibc version __GLIBC__ and __GLIBC_MINOR__*/
-#define __GLIBC_2_2     ((__GLIBC__ > 2) || ((__GLIBC__ >= 2) && (__GLIBC_MINOR__ >= 2)))
-			/* true if glibc-2.2 and older is used */
-#endif /* __QNX__ */
-
-#define _CPPLIB_VER	402
-
-		/* DETERMINE MACHINE TYPE */
-
- #if defined(i386) || defined(__i386) \
-	|| defined(__i386__) || defined(_M_IX86)	/* Pentium */
-  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
-   #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
-   #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-   #define _LOFF	15	/* 80/128 long double bits */
-  #define _FPP_TYPE	_FPP_X86	/* Pentium FPP */
-
- #elif defined(ia64) || defined(__ia64) || defined(__ia64__)	/* Itanium(R) */
-  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-  #define _LOFF		15	/* 80/128 long double bits */
-  #define _FPP_TYPE	_FPP_IA64	/* HP PA-RISC FPP */
-
- #else /* system detector */
-/* #error unknown compilation environment, guess big-endian */
-  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3fe	/* 64 long double bits */
-  #define _LOFF		4	/* 64 long double bits */
- #endif /* system detector */
-
-		/* DETERMINE _Ptrdifft AND _Sizet FROM MACHINE TYPE */
-
- #if defined(_MACH_I32)
-typedef _MACH_I32 _Int32t;
-typedef unsigned _MACH_I32 _Uint32t;
-
- #else /* defined(_MACH_I32) */
-  #if defined __QNX__
-typedef unsigned		 			_Uint32t __attribute__((__aligned__(4)));
-typedef int				 			_Int32t __attribute__((__aligned__(4)));
-  #else /* __QNX__ */
-typedef long _Int32t;
-typedef unsigned long _Uint32t;
-  #endif /* __QNX__  */
- #endif /* defined(_MACH_I32) */
-
- #if defined(_MACH_PDT)
-typedef _MACH_PDT _Ptrdifft;
-
- #else /* defined(_MACH_PDT) */
-typedef __PTRDIFF_TYPE__ _Ptrdifft;
- #endif /* defined(_MACH_PDT) */
-
- #if defined(_MACH_SZT)
-typedef _MACH_SZT _Sizet;
-
- #else /* defined(_MACH_SZT) */
-typedef __SIZE_TYPE__ _Sizet;
- #endif /* defined(_MACH_SZT) */
-
- #if defined(__linux)
-  #define _LINUX_C_LIB	1	/* Linux-specific conventions */
- #endif /* defined(__linux) */
-
-  #define _POSIX_C_LIB	1	/* use common Unix/Linux conventions */
-
  #if !defined(_HAS_C9X) && defined(_C99)
   #define _HAS_C9X	1
  #endif /* !defined(_HAS_C9X) etc. */
 
- #define _HAS_C9X_IMAGINARY_TYPE	(_HAS_C9X && __EDG__ \
-	&& !defined(__cplusplus))
-
  #if !defined(_ECPP) && defined(_ABRCPP)
   #define _ECPP
  #endif /* !defined(_ECPP) && defined(_ABRCPP) */
@@ -146,56 +53,8 @@
    #define _HAS_NAMESPACE	1	/* 1 for C++ names in std */
  #endif /* _HAS_NAMESPACE */
 
- #if !defined(_HAS_STRICT_LINKAGE) \
-	&& __EDG__
-  #define _HAS_STRICT_LINKAGE	1	/* extern "C" in function type */
- #endif /* !defined(_HAS_STRICT_LINKAGE) */
-
-		/* THREAD AND LOCALE CONTROL */
- #ifndef _MULTI_THREAD
-
-  #ifdef __CYGWIN__
-   #define _MULTI_THREAD	0	/* Cygwin has dummy thread library */
-
-  #else /* __CYGWIN__ */
-   #ifndef _NO_MT
-    #define _MULTI_THREAD	1	/* 0 for no thread locks */
-
-   #else
-    #define _MULTI_THREAD	0
-   #endif	/* _NO_MT */
-
-  #endif /* __CYGWIN__ */
- #endif /* _MULTI_THREAD */
-
-#define _GLOBAL_LOCALE	0	/* 0 for per-thread locales, 1 for shared */
-#define _FILE_OP_LOCKS	0	/* 0 for no FILE locks, 1 for atomic */
-
-#ifndef _IOSTREAM_OP_LOCKS
-  #define _IOSTREAM_OP_LOCKS	1	/* 0 for no iostream locks, 1 for atomic */
-#endif /* _IOSTREAM_OP_LOCKS */
-
-		/* THREAD-LOCAL STORAGE */
-#define _COMPILER_TLS	0	/* 1 if compiler supports TLS directly */
-#define _TLS_QUAL	/* TLS qualifier, such as __declspec(thread), if any */
-
- #define _HAS_PLACEMENT_DELETE	1
-
- #define _HAS_IMMUTABLE_SETS	1
- #define _HAS_TRADITIONAL_IOSTREAMS	1
- #define _HAS_TRADITIONAL_ITERATORS	1
- #define _HAS_TRADITIONAL_POS_TYPE	1
  #define _HAS_TRADITIONAL_STL	1
 
- #if !defined(_HAS_STRICT_CONFORMANCE)
-  #define _HAS_STRICT_CONFORMANCE	0	/* enable nonconforming extensions */
- #endif /* !defined(_HAS_STRICT_CONFORMANCE) */
-
- #if !defined(_HAS_ITERATOR_DEBUGGING) \
-	&& (defined(_STL_DB) || defined(_STLP_DEBUG))
-  #define _HAS_ITERATOR_DEBUGGING	1	/* for range checks, etc. */
- #endif /* define _HAS_ITERATOR_DEBUGGING */
-
 		/* NAMESPACE CONTROL */
  #if defined(__QNX__) && defined(__cplusplus)
   #define _STD_USING 1 /* To be compatible with QNX, where _STD_USING defined for C++ only */
@@ -283,221 +142,13 @@
   #define _END_EXTERN_C
  #endif /* __cplusplus */
 
- #if defined(__cplusplus)
-  #define _C99_float_complex	float __complex__
-  #define _C99_double_complex	double __complex__
-  #define _C99_ldouble_complex	long double __complex__
- #endif /* defined(__cplusplus) */
-
- #define _Restrict
-
- #ifdef __cplusplus
-_STD_BEGIN
-typedef bool _Bool;
-_STD_END
- #endif /* __cplusplus */
-
 		/* VC++ COMPILER PARAMETERS */
- #define _CRTIMP
  #define _CDECL
 
-  #define _LONGLONG	long long
-  #define _ULONGLONG	unsigned long long
-  #define _LLONG_MAX	0x7fffffffffffffffLL
-  #define _ULLONG_MAX	0xffffffffffffffffULL
-typedef _LONGLONG _Longlong;
-typedef _ULONGLONG _ULonglong;
-
-_C_STD_BEGIN
-		/* FLOATING-POINT PROPERTIES */
-#define _DBIAS	0x3fe	/* IEEE format double and float */
-#define _DOFF	4
-#define _FBIAS	0x7e
-#define _FOFF	7
-#define _FRND	1
-
-		/* INTEGER PROPERTIES */
-#define _BITS_BYTE	8
-#define _C2			1	/* 0 if not 2's complement */
-#define _MBMAX		8	/* MB_LEN_MAX */
-#define _ILONG		1	/* 0 if 16-bit int */
-
- #if defined(__CHAR_UNSIGNED__)  \
-	|| defined(_CHAR_UNSIGNED)
-  #define _CSIGN	0	/* 0 if char is not signed */
-
- #else /* defined(__CHAR_UNSIGNED__) etc */
-  #define _CSIGN	1
- #endif /* defined(__CHAR_UNSIGNED__) etc */
-
-#define _MAX_EXP_DIG	8	/* for parsing numerics */
-#define _MAX_INT_DIG	32
-#define _MAX_SIG_DIG	36
-
-		/* wchar_t AND wint_t PROPERTIES */
-
- #if defined(_WCHAR_T) || defined(_WCHAR_T_DEFINED) \
-	|| defined (_MSL_WCHAR_T_TYPE)
-  #define _WCHART
- #endif /* defined(_WCHAR_T) || defined(_WCHAR_T_DEFINED) */
-
- #if defined(_WINT_T)
-  #define _WINTT
- #endif /* _WINT_T */
-
- #ifdef __cplusplus
-  #define _WCHART
-typedef wchar_t _Wchart;
-  #ifdef __QNX__ 
-/* define _Wint and wint_t as QNX does */
-typedef long _Wintt;
-typedef _Wintt wint_t;
-  #else /* __QNX__ */
-/* Original _Wint definition */
-typedef wchar_t _Wintt;
-  #endif /* __QNX__ */
- #endif /* __cplusplus */
-
- #if defined(_MSL_WCHAR_T_TYPE)
-  #define _WCMIN	0
-  #define _WCMAX	0xffff
-
-  #ifndef __cplusplus
-typedef wchar_t _Wchart;
-typedef wint_t _Wintt;
-  #endif /* __cplusplus */
-
-  #define mbstate_t	_DNK_mbstate_t
-  #define wctype_t	_DNK_wctype_t
-  #define wint_t	_DNK_wint_t
-  #define _MSC_VER	1
-
- #elif defined(__CYGWIN__)
-  #define _WCMIN	(-_WCMAX - _C2)
-  #define _WCMAX	0x7fff
-
-  #ifndef __cplusplus
-typedef short _Wchart;
-typedef short _Wintt;
-  #endif /* __cplusplus */
-
- #elif defined(__WCHAR_TYPE__)
-  #define _WCMIN	(-_WCMAX - _C2)
-  #define _WCMAX	0x7fffffff	/* assume signed 32-bit wchar_t */
-
-  #ifndef __cplusplus
-   #ifndef __QNX__ /* _Wchart declared in QNX system headers */
-typedef __WCHAR_TYPE__ _Wchart;
-typedef __WCHAR_TYPE__ _Wintt;
-   #endif /* __QNX__ */
-  #endif /* __cplusplus */
-
- #else /* default wchar_t/wint_t */
-  #define _WCMIN	(-_WCMAX - _C2)
-  #define _WCMAX	0x7fffffff
-
-  #ifndef __cplusplus
-typedef long _Wchart;
-typedef long _Wintt;
-  #endif /* __cplusplus */
-
- #endif /* compiler/library type */
-
-		/* POINTER PROPERTIES */
-#define _NULL		0L	/* 0L if pointer same as long */
-
-		/* signal PROPERTIES */
-
-#define _SIGABRT	6
-#define _SIGMAX		44
-
-		/* stdarg PROPERTIES */
-#ifdef __x86_64__
-typedef __gnuc_va_list _Va_list;
-#else
-typedef va_list _Va_list;
-#endif
-
- #if _HAS_C9X
-
- #if __EDG__
-  #undef va_copy
- #endif /* __EDG__ */
-
- #ifndef va_copy
-_EXTERN_C
-void _Vacopy(_Va_list *, _Va_list);
-_END_EXTERN_C
-  #define va_copy(apd, aps)	_Vacopy(&(apd), aps)
- #endif /* va_copy */
-
- #endif /* _IS_C9X */
-
-		/* stdlib PROPERTIES */
-#define _EXFAIL	1	/* EXIT_FAILURE */
-
-_EXTERN_C
-void __Atexit(void (*)(void));
-_END_EXTERN_C
-
-		/* stdio PROPERTIES */
-#define _FNAMAX	260
-#define _FOPMAX	20
-#define _TNAMAX	16
-
- #define _FD_TYPE	int
-  #define _FD_NO(str) ((str)->_Handle)
- #define _FD_VALID(fd)	(0 <= (fd))	/* fd is signed integer */
- #define _FD_INVALID	(-1)
- #define _SYSCH(x)	x
-typedef char _Sysch_t;
-
-		/* STORAGE ALIGNMENT PROPERTIES */
-#define _MEMBND	3U /* eight-byte boundaries (2^^3) */
-
-		/* time PROPERTIES */
-#define _TBIAS	((70 * 365LU + 17) * 86400)
-_C_STD_END
-
-		/* MULTITHREAD PROPERTIES */
-_STD_BEGIN
- #if _MULTI_THREAD
-void _Locksyslock(int);
-void _Unlocksyslock(int);
-
- #else /* _MULTI_THREAD */
-  #define _Locksyslock(x)	(void)0
-  #define _Unlocksyslock(x)	(void)0
- #endif /* _MULTI_THREAD */
-_STD_END
-		/* LOCK MACROS */
- #define _LOCK_LOCALE	0
- #define _LOCK_MALLOC	1
- #define _LOCK_STREAM	2
- #define _LOCK_DEBUG	3
- #define _MAX_LOCK		4	/* one more than highest lock number */
-
- #if _IOSTREAM_OP_LOCKS
-  #define _MAYBE_LOCK
-
- #else /* _IOSTREAM_OP_LOCKS */
-  #define _MAYBE_LOCK	\
-	if (_Locktype == _LOCK_MALLOC || _Locktype == _LOCK_DEBUG)
- #endif /* _IOSTREAM_OP_LOCKS */
-
-		/* MISCELLANEOUS MACROS */
-#define _ATEXIT_T	void
-
-#define _MAX	(max)
-#define _MIN	(min)
-
 #define _TEMPLATE_STAT
 
  #if 0 < __GNUC__
   #define _NO_RETURN(fun)	void fun __attribute__((__noreturn__))
-
- #elif 1200 <= _MSC_VER
-  #define _NO_RETURN(fun)	__declspec(noreturn) void fun
 
  #else /* compiler selector */
   #define _NO_RETURN(fun)	void fun
