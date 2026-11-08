--- ui/zenomodel/src/globalcontrolmgr.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenomodel/src/globalcontrolmgr.cpp
@@ -45,7 +45,7 @@ CONTROL_INFO GlobalControlMgr::controlIn
     }
     if (coreType.startsWith("enum "))
     {
-        QStringList items = coreType.mid(QString("enum ").length()).split(QRegExp("\\s+"));
+        QStringList items = coreType.mid(QString("enum ").length()).split(QRegularExpression("\\s+"));
         QVariantMap map;
         map["items"] = items;
         return CONTROL_INFO(CONTROL_ENUM, map);
