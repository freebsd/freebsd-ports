--- encode_dxa.cpp.orig	2009-08-23 15:44:34.000000000 +0200
+++ encode_dxa.cpp	2012-04-29 06:59:57.000000000 +0200
@@ -25,6 +25,7 @@
 #include "util.h"
 
 #include <png.h>
+#include <pngpriv.h>
 
 const uint32 typeDEXA = 0x41584544;
 const uint32 typeFRAM = 0x4d415246;
