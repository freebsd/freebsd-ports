--- src/gusanos/blitters/mmx.h.orig	2010-02-17 19:59:26.000000000 +0300
+++ src/gusanos/blitters/mmx.h	2012-03-10 07:56:06.901704744 +0400
@@ -207,12 +207,4 @@
 #error "MMX capability only available on GCC!"
 #endif
 
-#ifndef always_inline
-#if defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ > 0)
-#    define always_inline __attribute__((always_inline)) inline
-#else
-#    define always_inline inline
-#endif
-#endif
-
 #endif //MMX_H
