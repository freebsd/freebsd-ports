--- src/HdrCreation/HdrCreationManager.cpp.prig	2008-04-29 01:18:04.000000000 +0900
+++ src/HdrCreation/HdrCreationManager.cpp	2008-07-02 03:26:00.000000000 +0900
@@ -28,6 +28,7 @@
 #include "../Exif/exif_operations.h"
 #include "mtb_alignment.h"
 #include "../Threads/hdrInputLoader.h"
+#include "../arch/freebsd/math.h"
 
 HdrCreationManager::HdrCreationManager() {
 	qtpfsgui_options=QtpfsguiOptions::getInstance();
