--- librawstudio/rs-macros.h	2014-02-19 06:34:15.000000000 +0100
+++ librawstudio/rs-macros.h	2014-02-19 06:34:21.000000000 +0100
@@ -51,12 +51,12 @@
 #if __GNUC__ >= 3
 #define likely(x) __builtin_expect (!!(x), 1)
 #define unlikely(x) __builtin_expect (!!(x), 0)
-#define align(x) __attribute__ ((aligned (x)))
+// #define align(x) __attribute__ ((aligned (x)))
 #define __deprecated __attribute__ ((deprecated))
 #else
 #define likely(x) (x)
 #define unlikely(x) (x)
-#define align(x)
+// #define align(x)
 #define __deprecated
 #endif
