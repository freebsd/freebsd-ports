--- src/osd/eminline.h.orig	2018-02-27 15:59:06 UTC
+++ src/osd/eminline.h
@@ -21,7 +21,7 @@
 
 #if defined(__GNUC__)
 
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__x86_64__) || defined(__amd64__)
 #include "eigccx86.h"
 #elif defined(__ppc__) || defined (__PPC__) || defined(__ppc64__) || defined(__PPC64__)
 #include "eigccppc.h"
