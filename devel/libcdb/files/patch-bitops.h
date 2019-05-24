--- bitops.h.orig	2018-06-11 23:57:47 UTC
+++ bitops.h
@@ -36,12 +36,14 @@
 #else
 #include <stdint.h>
 
+#ifndef __GNUC_PREREQ__
 #ifdef __GNUC__
 #define	__GNUC_PREREQ__(x, y)						\
 	((__GNUC__ == (x) && __GNUC_MINOR__ >= (y)) ||			\
 	 (__GNUC__ > (x)))
 #else
 #define	__GNUC_PREREQ__(x, y)	0
+#endif
 #endif
 
 #ifndef __unused
