--- pcsx2/SPU2/spu2.cpp.orig	2020-10-29 23:31:05 UTC
+++ pcsx2/SPU2/spu2.cpp
@@ -17,7 +17,10 @@
 #include "Global.h"
 #include "spu2.h"
 #include "Dma.h"
-#ifdef __linux__
+#ifdef __BSD__
+#include "Linux/Dialogs.h"
+#include "Linux/Config.h"
+#elif defined(__linux__)
 #include "Linux/Dialogs.h"
 #include "Linux/Config.h"
 #elif defined(_WIN32)
