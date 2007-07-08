--- src/libffwma/dsputil.h.orig	2007-07-08 09:40:03.000000000 +0400
+++ src/libffwma/dsputil.h	2007-07-08 09:50:14.000000000 +0400
@@ -509,14 +509,4 @@
     return score;\
 }
 
-#ifndef HAVE_LRINTF
-/* XXX: add ISOC specific test to avoid specific BSD testing. */
-/* better than nothing implementation. */
-/* btw, rintf() is existing on fbsd too -- alex */
-static inline long int lrintf(float x)
-{
-    return (int)(rint(x));
-}
-#endif
-
 #endif
