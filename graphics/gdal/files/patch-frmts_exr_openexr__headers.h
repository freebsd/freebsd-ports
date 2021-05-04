--- frmts/exr/openexr_headers.h.orig	2021-03-05 04:40:24 UTC
+++ frmts/exr/openexr_headers.h
@@ -35,6 +35,7 @@
 #pragma GCC system_header
 #endif
 
+#include "ImathInt64.h"
 #include "ImathMatrix.h"
 #include "ImfChannelList.h"
 #include "ImfFloatAttribute.h"
@@ -42,6 +43,7 @@
 #include "ImfMatrixAttribute.h"
 #include "ImfMultiPartInputFile.h"
 #include "ImfMultiPartOutputFile.h"
+#include "ImfOutputPart.h"
 #include "ImfPartType.h"
 #include "ImfPreviewImage.h"
 #include "ImfRgbaFile.h"
