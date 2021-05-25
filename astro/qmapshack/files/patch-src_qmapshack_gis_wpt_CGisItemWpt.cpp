--- src/qmapshack/gis/wpt/CGisItemWpt.cpp.orig	2021-05-24 09:18:08 UTC
+++ src/qmapshack/gis/wpt/CGisItemWpt.cpp
@@ -40,6 +40,7 @@
 #include <QPainterPath>
 #include <QtWidgets>
 #include <QtXml>
+#include <QPainterPath>
 
 IGisItem::key_t CGisItemWpt::keyUserFocus;
 QMap<searchProperty_e, CGisItemWpt::fSearch> CGisItemWpt::keywordLambdaMap;
