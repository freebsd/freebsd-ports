--- ./shared/shared.h.orig	Tue May 23 20:05:59 2006
+++ ./shared/shared.h	Tue May 23 20:06:00 2006
@@ -41,6 +41,15 @@
 //R1Q2 SPECIFC
 
 // =========================================================================
+// Common
+//
+#ifdef NDEBUG
+# define DEBUG_STR		""
+#else
+# define DEBUG_STR		" Debug"
+#endif
+
+// =========================================================================
 // Windows
 //
 #ifdef WIN32
@@ -68,23 +77,15 @@
 
 # define BUILDSTRING		"Win32"
 
-# ifdef NDEBUG
-#  ifdef _M_IX86
-#   define CPUSTRING		"x86"
-#  elif defined _M_ALPHA
-#   define CPUSTRING		"AXP"
-#  endif
-# else // NDEBUG
-#  ifdef _M_IX86
-#   define CPUSTRING		"x86 Debug"
-#  elif defined _M_ALPHA
-#   define CPUSTRING		"AXP Debug"
-#  endif
-# endif // NDEBUG
+# ifdef _M_IX86
+#  define CPUSTRING		"x86"
+# elif defined _M_ALPHA
+#  define CPUSTRING		"AXP"
+# endif
 
-typedef __int16				int16;
-typedef __int32				int32;
-typedef __int64				int64;
+typedef __int16			int16;
+typedef __int32			int32;
+typedef __int64			int64;
 typedef unsigned __int16	uint16;
 typedef unsigned __int32	uint32;
 typedef unsigned __int64	uint64;
@@ -94,49 +95,35 @@
 # define __declspec_naked __declspec(naked)
 
 // =========================================================================
-// Linux
+// Unix in general (Linux, *BSD, etc)
 //
-#elif defined __linux__
-# include <stdint.h>
-
-# define GL_DRIVERNAME		"libGL.so.1"
-# define AL_DRIVERNAME		"libopenal.so.0"
-# define GL_FORCEFINISH
+#elif defined __unix__
 
-# define HAVE_INLINE
-# define HAVE_STRCASECMP
+// Linux
+# if defined(__linux__)
+#  include <stdint.h>
 
-# define BUILDSTRING		"Linux"
+#  define BUILDSTRING		"Linux"
 
-# ifdef NDEBUG
-#  ifdef __i386__
-#   define CPUSTRING		"i386"
-#  elif defined(__alpha__)
-#   define CPUSTRING		"AXP"
-#  endif
-# else // NDEBUG
-#  ifdef __i386__
-#   define CPUSTRING		"i386 Debug"
-#  elif defined(__alpha__)
-#   define CPUSTRING		"AXP Debug"
+// FreeBSD
+# elif defined __FreeBSD__
+#  include <machine/param.h>
+#  if __FreeBSD_version < 500000
+#   include <inttypes.h>
+#  else
+#   include <stdint.h>
 #  endif
-# endif // NDEBUG
 
-typedef int16_t				int16;
-typedef int32_t				int32;
-typedef int64_t				int64;
-typedef uint16_t			uint16;
-typedef uint32_t			uint32;
-typedef uint64_t			uint64;
+#  define BUILDSTRING		"FreeBSD"
 
-# define __declspec
-# define __declspec_naked
+# else
+#  include <stdint.h>
+# endif
 
-// =========================================================================
-// FreeBSD
-//
-#elif defined __FreeBSD__
-# include <stdint.h>
+// Common
+# ifdef ARCH
+#  define CPUSTRING		ARCH
+# endif
 
 # define GL_DRIVERNAME		"libGL.so.1"
 # define AL_DRIVERNAME		"libopenal.so.0"
@@ -145,22 +132,6 @@
 # define HAVE_INLINE
 # define HAVE_STRCASECMP
 
-# define BUILDSTRING		"FreeBSD"
-
-# ifdef NDEBUG
-#  ifdef __i386__
-#   define CPUSTRING		"i386"
-#  elif defined(__alpha__)
-#   define CPUSTRING		"AXP"
-#  endif
-# else // NDEBUG
-#  ifdef __i386__
-#   define CPUSTRING		"i386 Debug"
-#  elif defined(__alpha__)
-#   define CPUSTRING		"AXP Debug"
-#  endif
-# endif // NDEBUG
-
 typedef int16_t				int16;
 typedef int32_t				int32;
 typedef int64_t				int64;
@@ -225,7 +196,7 @@
 
 // =========================================================================
 
-#if (defined(_M_IX86) || defined(__i386__)) && !defined(C_ONLY) && !defined(__linux__) && !defined(__FreeBSD__) // FIXME: make this work with linux
+#if (defined(_M_IX86) || defined(__i386__)) && !defined(C_ONLY) && !defined(__unix__) // FIXME: make this work with linux
 # define id386
 #else
 # ifdef id386
@@ -233,14 +204,6 @@
 # endif
 #endif
 
-#if !defined(ENDIAN_LITTLE) && !defined(ENDIAN_BIG)
-# if defined(__i386__) || defined(__ia64__) || defined(WIN32) || (defined(__alpha__) || defined(__alpha)) || defined(__arm__) || (defined(__mips__) && defined(__MIPSEL__)) || defined(__LITTLE_ENDIAN__)
-#  define ENDIAN_LITTLE
-# else
-#  define ENDIAN_BIG
-# endif
-#endif
-
 #ifndef BUILDSTRING
 # define BUILDSTRING	"Unknown"
 #endif
@@ -755,100 +718,17 @@
 ==============================================================================
 
 	BYTE ORDER FUNCTIONS
- 
-==============================================================================
-*/
-
-#ifdef USE_BYTESWAP
-
-/*
-===============
-FloatSwap
-===============
-*/
-static inline float FloatSwap (float f)
-{
-	union {
-		byte	b[4];
-		float	f;
-	} in, out;
-	
-	in.f = f;
 
-	out.b[0] = in.b[3];
-	out.b[1] = in.b[2];
-	out.b[2] = in.b[1];
-	out.b[3] = in.b[0];
-	
-	return out.f;
-}
-
-
-/*
-===============
-LongSwap
-===============
-*/
-static inline int LongSwap (int l)
-{
-	union {
-		byte	b[4];
-		int		l;
-	} in, out;
-
-	in.l = l;
-
-	out.b[0] = in.b[3];
-	out.b[1] = in.b[2];
-	out.b[2] = in.b[1];
-	out.b[3] = in.b[0];
-
-	return out.l;
-}
-
-/*
-===============
-ShortSwap
-===============
+==============================================================================
 */
-static inline int16 ShortSwap (int16 s)
-{
-	union {
-		byte	b[2];
-		int16	s;
-	} in, out;
-
-	in.s = s;
 
-	out.b[0] = in.b[1];
-	out.b[1] = in.b[0];
-
-	return out.s;
-}
-
-#if defined(WIN32) || defined(__linux__) || defined(__FreeBSD__)
-
-#define LittleFloat
-#define LittleLong
-#define LittleShort
-
-static inline float	BigFloat (float f)		{ return FloatSwap (f);	}
-static inline int	BigLong (int l)			{ return LongSwap (l);	}
-static inline int16	BigShort (int16 s)		{ return ShortSwap (s);	}
-
-#elif (defined __MACOS__ || defined MACOS_X)
-
-#define BigFloat
-#define BigLong
-#define BigShort
-
-static inline float	LittleFloat (float f)	{ return FloatSwap (f);	}
-static inline int	LittleLong (int l)		{ return LongSwap (l);	}
-static inline int16	LittleShort (int16 s)	{ return ShortSwap (s);	}
-
-#endif
-
-#endif // USE_BYTESWAP
+int16	LittleShort (int16 l);
+int32	LittleLong (int32 l);
+float	LittleFloat (float l);
+int16	BigShort (int16 l);
+int32	BigLong (int32 l);
+float	BigFloat (float l);
+void	Swap_Init (void);
 
 /*
 ==============================================================================
