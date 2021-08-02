--- src/exr.cpp.orig	2021-08-02 02:30:54 UTC
+++ src/exr.cpp
@@ -22,10 +22,8 @@
  *
  */
 
-extern "C" {
 #include "histogram-imager.h"
 #include "config.h"
-}
 
 #include <ImfRgbaFile.h>
 using namespace Imf;
