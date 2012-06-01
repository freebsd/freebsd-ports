--- src/formats/formatpng.cpp.orig	2010-08-29 16:33:33.000000000 +0200
+++ src/formats/formatpng.cpp	2012-05-05 07:46:22.000000000 +0200
@@ -7,6 +7,7 @@
 
 #include "formatpng.h"
 #include <png.h>
+#include <pngpriv.h>
 #include <string.h>
 #include <iostream>
 
