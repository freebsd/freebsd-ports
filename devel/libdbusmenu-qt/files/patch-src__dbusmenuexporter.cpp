--- ./src/dbusmenuexporter.cpp.orig	2010-09-23 10:08:35.000000000 +0000
+++ ./src/dbusmenuexporter.cpp	2010-11-12 14:49:39.000000000 +0000
@@ -79,6 +79,7 @@
 {
     QVariantMap map;
     map.insert("enabled", false);
+    map.insert("x-kde-title", true);
 
     const QWidgetAction *widgetAction = qobject_cast<const QWidgetAction *>(action_);
     DMRETURN_VALUE_IF_FAIL(widgetAction, map);
