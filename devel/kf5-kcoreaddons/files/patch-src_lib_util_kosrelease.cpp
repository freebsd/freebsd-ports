--- src/lib/util/kosrelease.cpp.orig	2019-05-08 08:27:20 UTC
+++ src/lib/util/kosrelease.cpp
@@ -76,13 +76,18 @@ static QStringList splitEntry(const QString &line)
 
 static QString defaultFilePath()
 {
-    if (QFile::exists(QStringLiteral("/etc/os-release"))) {
-        return QStringLiteral("/etc/os-release");
-    } else if (QFile::exists(QStringLiteral("/usr/lib/os-release"))) {
-        return QStringLiteral("/usr/lib/os-release");
-    } else {
-        return QString();
+    for (const auto& path : { 
+#ifdef Q_OS_FREEBSD
+        QStringLiteral("/usr/local/etc/os-release"),
+#endif
+        QStringLiteral("/etc/os-release"),
+        QStringLiteral("/usr/lib/os-release")
+        }) {
+        if (QFile::exists(path)) {
+            return path;
+        }
     }
+    return QString();
 }
 
 class Q_DECL_HIDDEN KOSRelease::Private
