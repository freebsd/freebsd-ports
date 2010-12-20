--- ./src/dbusmenuexporter.cpp.orig	2010-12-08 10:29:39.000000000 +0100
+++ ./src/dbusmenuexporter.cpp	2010-12-20 12:18:44.673410726 +0100
@@ -84,6 +84,7 @@
 {
     QVariantMap map;
     map.insert("enabled", false);
+    map.insert("x-kde-title", true);
 
     const QWidgetAction *widgetAction = qobject_cast<const QWidgetAction *>(action_);
     DMRETURN_VALUE_IF_FAIL(widgetAction, map);
