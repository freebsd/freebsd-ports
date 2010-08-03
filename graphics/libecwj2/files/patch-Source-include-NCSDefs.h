--- Source/include/NCSDefs.h.orig	2006-07-03 05:15:22.000000000 +0400
+++ Source/include/NCSDefs.h	2010-07-29 16:08:26.000000000 +0400
@@ -57,10 +57,12 @@
 #define NCS_64BIT
 #endif
 
-#if (defined(MACINTOSH)||defined(SOLARIS)||defined(IRIX)||defined(PALM)||defined(HPUX)||defined(MACOSX))&&(!defined(X86))
-#define NCSBO_MSBFIRST
-#else	// WIN32, LINUX (i386)
-#define NCSBO_LSBFIRST
+#include <machine/endian.h>
+
+#if (BYTE_ORDER == LITTLE_ENDIAN)
+#define	NCSBO_LSBFIRST
+#else
+#define	NCSBO_MSBFIRST
 #endif
 
 #if !defined(_WIN32_WCE)&&!defined(UNALIGNED)
@@ -180,13 +182,15 @@
 #define IntersectRect(A, B, C) SectRect(B, C, A)
 #define 	ZeroMemory(DATA, SIZE) memset(DATA, 0, SIZE)
 
-#elif defined SOLARIS || defined LINUX || defined HPUX
+#elif defined SOLARIS || defined LINUX || defined HPUX || defined FREEBSD
 
-#ifdef LINUX
+#if defined LINUX || defined FREEBSD
 #define wcsicmp wcscasecmp
 #endif
 
+#ifndef FREEBSD
 #include <values.h>
+#endif
 #include <limits.h>
 #include <ctype.h>
 #include <math.h>
@@ -195,7 +199,7 @@
 #define MAXDOUBLE   DBL_MAX			//1.7976931348623158e+308
 #endif	/* !MAXDOUBLE */
 
-#ifdef LINUX
+#if defined LINUX || defined FREEBSD
 #define NCS_FQNAN	NAN	//0x0002
 #define NCS_NAN		NAN
 #elif defined(SOLARIS)
@@ -299,7 +303,7 @@
 
 #define MAX_PATH 	1024
 
-#elif defined SOLARIS || defined LINUX || defined HPUX
+#elif defined SOLARIS || defined LINUX || defined HPUX || defined FREEBSD
 
 #define MAX_PATH	PATH_MAX
 
