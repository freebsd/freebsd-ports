--- ../tools/inc/solar.h	2001/10/12 15:11:03	1.23
+++ ../tools/inc/solar.h	2002/03/03 19:44:00
@@ -108,7 +108,7 @@
 #endif
 typedef short				INT16;
 typedef unsigned short		UINT16;
-#if defined LINUX || defined SCO || defined IRIX || (defined _MSC_VER && _MSC_VER >1200)
+#if defined LINUX || defined SCO || defined IRIX || (defined _MSC_VER && _MSC_VER >1200) || defined FREEBSD
 typedef signed char 		INT8;
 #else
 
@@ -149,7 +149,7 @@
 
 /*** misc. macros to leverage platform and compiler differences ********/
 
-#if (defined ALPHA && !defined WNT) || defined IRIX || defined SOLARIS || defined HPUX || defined NETBSD
+#if (defined ALPHA && !defined WNT) || defined IRIX || defined SOLARIS || defined HPUX || defined NETBSD || defined FREEBSD
 #define __DELETE(n) delete[]
 #else
 #define __DELETE(n) delete[n]
