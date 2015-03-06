--- src/interface/Mainfrm.h.orig	2015-03-05 03:48:01 UTC
+++ src/interface/Mainfrm.h
@@ -28,6 +28,8 @@ class CWindowStateManager;
 
 #if FZ_MANUALUPDATECHECK
 #include "updater.h"
+#else
+#include <wx/timer.h>
 #endif
 class CWindowStateManager;
 
