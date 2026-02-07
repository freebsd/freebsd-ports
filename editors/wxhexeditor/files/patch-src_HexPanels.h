--- src/HexPanels.h.orig	2017-12-31 02:15:18 UTC
+++ src/HexPanels.h
@@ -27,7 +27,7 @@
 #include "HexEditorFrame.h"
 #include "HexEditorCtrl/HexEditorCtrl.h"
 #include "HexEditorCtrl/wxHexCtrl/wxHexCtrl.h"
-#include "../udis86/udis86.h"
+#include <udis86.h>
 
 #ifdef WX_GCH
 #include <wx_pch.h>
