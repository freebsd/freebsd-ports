--- app/app/app.cpp.orig	2023-01-16 19:49:55 UTC
+++ app/app/app.cpp
@@ -63,6 +63,10 @@ QStringList App::nodePaths() const
     // If we're running Antimony from the build folder, use sb/nodes
     paths << applicationDirPath() + "/sb/nodes";
     paths << applicationDirPath() + "/../share/antimony/nodes";
+#elif defined Q_OS_FREEBSD
+    // If we're running Antimony from the build folder, use sb/nodes
+    paths << applicationDirPath() + "/sb/nodes";
+    paths << applicationDirPath() + "/../share/antimony/nodes";
 #elif defined Q_OS_WIN32
     // Windows only supports running from the build directory
     paths << applicationDirPath() + "/sb/nodes";
