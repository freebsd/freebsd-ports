--- operations/external/exr-save.cc.orig	2021-03-27 19:13:57 UTC
+++ operations/external/exr-save.cc
@@ -45,6 +45,7 @@ extern "C" {
 #include <ImfChromaticities.h>
 #include <ImfStandardAttributes.h>
 #include <ImfArray.h>
+#include <ImfFrameBuffer.h>
 #include "ImathRandom.h"
 
 
