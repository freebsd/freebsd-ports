--- src/tracker/EQConstants.cpp.orig	2018-02-24 17:43:23 UTC
+++ src/tracker/EQConstants.cpp
@@ -23,7 +23,7 @@
 #include "EQConstants.h"
 #include "math.h"
 
-#define p(e) ldexp(0x10558, e-4*4)
+#define p(e) ldexp(66904.0f, e-4*4)
 
 const float EQConstants::EQ3bands[3] = 
 {
