--- designerPlugin/designerPlugin.pro.orig	2017-12-18 16:48:34 UTC
+++ designerPlugin/designerPlugin.pro
@@ -20,7 +20,7 @@ QT_VERSION=$$[QT_VERSION]
   }
 }
 
-target.path = $${PREFIX}/designer
+target.path = $${PREFIX}/lib/qt5/plugins/designer
 INSTALLS += target
 
 HEADERS = qglviewerPlugin.h
