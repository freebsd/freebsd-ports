--- misc/magic.h.orig	Fri Sep 21 17:15:45 2001
+++ misc/magic.h	Sat Jan 31 13:07:11 2004
@@ -18,6 +18,8 @@
  * rcsid="$Header"
  */
 
+#include <machine/endian.h>
+
 #define	_MAGIC
 
 /* Note:  System files, such as "stdio.h" and "sys/types.h", should be
@@ -146,6 +148,12 @@
  *
  */
 
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define	IS_LITTLE_ENDIAN
+#elif BYTE_ORDER == BIG_ENDIAN
+#define	IS_BIG_ENDIAN
+#endif
+
 #ifdef        i386
 #define       IS_LITTLE_ENDIAN        /* Intel x86 processors. */
 #endif
@@ -224,7 +232,7 @@
 #if defined(sun) && !defined(sparc)
 # define NEED_MONCNTL
 #endif  
-#ifdef	ALPHA
+#if defined(ALPHA) || (defined(__alpha__) && defined(__FreeBSD__))
 # define NEED_MONCNTL
 #endif  
 
