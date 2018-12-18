--- client/vector/analyzeFuncs_altivec.cpp.orig	2018-01-14 23:02:12 UTC
+++ client/vector/analyzeFuncs_altivec.cpp
@@ -31,7 +31,7 @@
 // This file is empty is USE_ALTIVEC is not defined
 #include "sah_config.h"
 
-#if defined(__ppc__) && defined(USE_ALTIVEC)
+#if defined(__ppc__) && defined(USE_ALTIVEC) && defined(__APPLE__)
 
 #define INVALID_CHIRP 2e+20
 
