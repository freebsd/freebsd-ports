--- glimits.h.orig	Wed Sep 29 14:30:54 1993
+++ glimits.h	Mon Mar 20 13:29:11 2000
@@ -63,7 +63,11 @@
 /* Minimum and maximum values a `signed long int' can hold.
    (Same as `int').  */
 #ifndef __LONG_MAX__
-#define __LONG_MAX__ 2147483647L
+# ifndef __alpha__
+#  define __LONG_MAX__ 2147483647L
+# else
+#  define __LONG_MAX__ 9223372036854775807L
+# endif /* __alpha__ */
 #endif
 #undef LONG_MIN
 #define LONG_MIN (-LONG_MAX-1)
