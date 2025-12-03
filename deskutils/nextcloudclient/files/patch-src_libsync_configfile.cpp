--- src/libsync/configfile.cpp.orig	2025-12-03 14:37:03 UTC
+++ src/libsync/configfile.cpp
@@ -626,11 +626,13 @@ bool ConfigFile::skipUpdateCheck(const QString &connec
 bool ConfigFile::skipUpdateCheck(const QString &connectionGroupName) const
 {
     const auto groupName = connectionGroupName.isEmpty() ? defaultConnectionGroupName() : connectionGroupName;
-    QVariant fallback = getValue(QLatin1String(skipUpdateCheckC), groupName, false);
+    QVariant fallback = getValue(QLatin1String(skipUpdateCheckC), groupName, true);
     fallback = getValue(QLatin1String(skipUpdateCheckC), QString(), fallback);
 
     QVariant value = getPolicySetting(QLatin1String(skipUpdateCheckC), fallback);
-    return value.toBool();
+    if ( !value.toBool() )
+      qDebug() << "FreeBSD package disabled the UpdateCheck mechanism.";
+    return true;
 }
 
 void ConfigFile::setSkipUpdateCheck(bool skip, const QString &connectionGroupName)
