--- src/osd/eminline.h.orig
+++ src/osd/eminline.h
@@ -17,7 +17,7 @@
 /* we come with implementations for GCC x86 and PPC */
 #if defined(__GNUC__)
 
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
 #include "eigccx86.h"
 #elif defined(__ppc__) || defined (__PPC__) || defined(__ppc64__) || defined(__PPC64__)
 #include "eigccppc.h"
