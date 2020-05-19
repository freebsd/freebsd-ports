--- src/widgets/freespacebar.cpp.orig	2020-05-19 17:40:21 UTC
+++ src/widgets/freespacebar.cpp
@@ -20,6 +20,7 @@
 
 #include <QLinearGradient>
 #include <QPainter>
+#include <QPainterPath>
 
 const int FreeSpaceBar::kBarHeight = 20;
 const int FreeSpaceBar::kBarBorderRadius = 8;
