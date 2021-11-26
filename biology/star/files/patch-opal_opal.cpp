--- opal/opal.cpp.orig	2021-11-26 16:14:46 UTC
+++ opal/opal.cpp
@@ -5,10 +5,8 @@
 #include <limits>
 #include <vector>
 
-extern "C" {
 #define SIMDE_ENABLE_NATIVE_ALIASES
 #include <simde_avx2.h> // AVX2 and lower
-}
 
 #include "opal.h"
 
