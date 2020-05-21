--- src/qmaptool/overlay/COverlayCutMap.cpp.orig	2020-05-21 11:11:11 UTC
+++ src/qmaptool/overlay/COverlayCutMap.cpp
@@ -24,6 +24,8 @@
 
 #include <functional>
 #include <QtWidgets>
+#include <QPainterPath>
+
 using std::bind;
 
 static inline qreal sqr(qreal a)
