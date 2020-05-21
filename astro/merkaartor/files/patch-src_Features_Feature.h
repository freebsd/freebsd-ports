--- src/Features/Feature.h.orig	2020-05-21 10:34:19 UTC
+++ src/Features/Feature.h
@@ -10,6 +10,7 @@ class Feature;
 
 #include <QtCore/QString>
 #include <QList>
+#include <QPainterPath>
 
 #define CAST_FEATURE(x) (dynamic_cast<Feature*>(x))
 #define CAST_NODE(x) (dynamic_cast<Node*>(x))
