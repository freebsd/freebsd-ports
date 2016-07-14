--- dutil.h.orig	2012-03-20 16:17:25 UTC
+++ dutil.h
@@ -25,7 +25,9 @@
 #define __pure __attribute__ ((pure))
 #endif
 
+#ifndef roundup
 #define roundup(x,y) ((((x) + ((y) - 1)) / (y)) * (y))
+#endif
 
 static inline __attribute__((const)) bool is_power_of_2(unsigned long n)
 {
