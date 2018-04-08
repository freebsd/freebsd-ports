--- kerfuffle/pluginmanager.cpp.orig	2018-03-03 22:55:29 UTC
+++ kerfuffle/pluginmanager.cpp
@@ -258,7 +258,7 @@ QStringList PluginManager::sortByComment
 bool PluginManager::libarchiveHasLzo()
 {
     // Step 1: look for the libarchive plugin, which is built against libarchive.
-    const QString pluginPath = []() {
+    const QString pluginPath = []() -> const QString {
         foreach (const QString &path, QCoreApplication::libraryPaths()) {
             const QString pluginPath = QStringLiteral("%1/kerfuffle/kerfuffle_libarchive.so").arg(path);
             if (QFileInfo::exists(pluginPath)) {
