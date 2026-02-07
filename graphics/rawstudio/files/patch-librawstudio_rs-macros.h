--- librawstudio/rs-macros.h.orig	2011-02-15 17:28:05 UTC
+++ librawstudio/rs-macros.h
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
 
