--- resis/ResRex.c.orig	Sat Sep 22 00:15:50 2001
+++ resis/ResRex.c	Mon Oct 14 20:50:32 2002
@@ -10,7 +10,7 @@
 /* It is hard to get the value of MAXFLOAT in a portable manner. */
 #if defined(ibm032) || defined(CYGWIN) 
 #define MAXFLOAT        ((float)3.40282346638528860e+38)
-#elif !defined(__NetBSD__)
+#elif !defined(__NetBSD__) && !defined(__FreeBSD__)
 #include <values.h>
 #endif
 
