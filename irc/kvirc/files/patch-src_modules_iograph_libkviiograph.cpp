--- src/modules/iograph/libkviiograph.cpp.orig	2020-05-18 14:33:26 UTC
+++ src/modules/iograph/libkviiograph.cpp
@@ -35,6 +35,7 @@
 
 #include <QPainter>
 #include <QPaintEvent>
+#include <QPainterPath>
 
 #ifdef COMPILE_PSEUDO_TRANSPARENCY
 extern KVIRC_API QPixmap * g_pShadedChildGlobalDesktopBackground;
