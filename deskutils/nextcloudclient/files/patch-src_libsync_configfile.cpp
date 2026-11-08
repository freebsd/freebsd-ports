--- src/libsync/configfile.cpp.orig	2026-10-29 04:04:20 UTC
+++ src/libsync/configfile.cpp
@@ -667,7 +667,10 @@ bool ConfigFile::skipUpdateCheck(const QString &connec
 
 bool ConfigFile::skipUpdateCheck(const QString &connectionGroupName) const
 {
-    return getConfig<bool>(QLatin1String(skipUpdateCheckC), connectionGroupName);
+    if (!getConfig<bool>(QLatin1String(skipUpdateCheckC), connectionGroupName)) {
+        qDebug() << "FreeBSD package disabled the UpdateCheck mechanism.";
+    }
+    return true;
 }
 
 void ConfigFile::setSkipUpdateCheck(bool skip, const QString &connectionGroupName)
