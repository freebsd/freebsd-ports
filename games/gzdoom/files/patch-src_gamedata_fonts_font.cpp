--- src/gamedata/fonts/font.cpp.orig	2019-05-03 16:07:35 UTC
+++ src/gamedata/fonts/font.cpp
@@ -35,6 +35,7 @@
 
 // HEADER FILES ------------------------------------------------------------
 
+#include <cwctype>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
