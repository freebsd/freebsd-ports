--- src/qmapshack/gis/wpt/CGisItemWpt.cpp.orig	2020-05-21 11:11:11 UTC
+++ src/qmapshack/gis/wpt/CGisItemWpt.cpp
@@ -38,6 +38,7 @@
 
 #include <QtWidgets>
 #include <QtXml>
+#include <QPainterPath>
 
 IGisItem::key_t CGisItemWpt::keyUserFocus;
 QMap<searchProperty_e, CGisItemWpt::fSearch> CGisItemWpt::keywordLambdaMap;
