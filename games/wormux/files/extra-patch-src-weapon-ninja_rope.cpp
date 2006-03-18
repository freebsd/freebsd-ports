--- src/weapon/ninja_rope.cpp.orig	Fri Feb 10 01:00:05 2006
+++ src/weapon/ninja_rope.cpp	Fri Feb 10 01:01:05 2006
@@ -37,6 +37,8 @@
 #include "../tool/math_tools.h"
 #include "../weapon/weapon_tools.h"
 
+#define round(a) (((a)-floor(a)) < 0.5 ? floor(a) : ceil(a))
+
 /*
 // Is this hack still needed for round()?
 #ifdef WIN32
