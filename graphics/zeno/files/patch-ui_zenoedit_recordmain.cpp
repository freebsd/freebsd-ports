--- ui/zenoedit/recordmain.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/recordmain.cpp
@@ -15,6 +15,7 @@
 #include <zeno/utils/log.h>
 #include "common.h"
 #include <rapidjson/document.h>
+#include "zenoapplication.h"
 
 
 //--record true --zsg "C:\zeno-master\render_param.zsg" --cachePath "C:\tmp" --sframe 0 --frame 10 --sample 1 --optix 0 --path "C:\recordpath" --pixel 4500x3500 --aov 0 --needDenoise 0
@@ -203,7 +204,7 @@ int record_main(const QCoreApplication&
     }
 
     if (!param.bOptix) {
-        ZenoMainWindow tempWindow(nullptr, 0, !param.bOptix ? PANEL_GL_VIEW : PANEL_EMPTY);
+        ZenoMainWindow tempWindow(nullptr, Qt::WindowFlags(), !param.bOptix ? PANEL_GL_VIEW : PANEL_EMPTY);
         tempWindow.hide();
         tempWindow.solidRunRender(param, launchparam);
         //idle
