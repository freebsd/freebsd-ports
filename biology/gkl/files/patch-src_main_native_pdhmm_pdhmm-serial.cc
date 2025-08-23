--- src/main/native/pdhmm/pdhmm-serial.cc.orig	2025-08-23 18:12:32 UTC
+++ src/main/native/pdhmm/pdhmm-serial.cc
@@ -24,7 +24,7 @@
 #include "pdhmm-serial.h"
 #include "MathUtils.h"
 #include <cstdio>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <omp.h>
 #endif
 
