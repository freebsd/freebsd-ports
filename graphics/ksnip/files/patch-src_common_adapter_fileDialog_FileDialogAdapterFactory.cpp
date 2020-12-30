--- src/common/adapter/fileDialog/FileDialogAdapterFactory.cpp.orig	2020-12-30 20:58:35 UTC
+++ src/common/adapter/fileDialog/FileDialogAdapterFactory.cpp
@@ -21,7 +21,7 @@
 
 IFileDialogAdapter *FileDialogAdapterFactory::create()
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	CommandRunner commandRunner;
 	auto isSnap = commandRunner.isEnvironmentVariableSet(QStringLiteral("SNAP"));
 	if (isSnap) {
