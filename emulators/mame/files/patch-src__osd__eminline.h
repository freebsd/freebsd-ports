--- src/osd/eminline.h.orig	2015-05-24 15:52:19 UTC
+++ src/osd/eminline.h
@@ -88,7 +88,7 @@ _osd_exchange64(INT64 volatile *ptr, INT
 
 #endif
 
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__x86_64__) || defined(__amd64__)
 #include "eigccx86.h"
 #elif defined(__ppc__) || defined (__PPC__) || defined(__ppc64__) || defined(__PPC64__)
 #include "eigccppc.h"
