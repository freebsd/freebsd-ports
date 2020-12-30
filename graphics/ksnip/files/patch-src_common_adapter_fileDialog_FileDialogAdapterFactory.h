--- src/common/adapter/fileDialog/FileDialogAdapterFactory.h.orig	2020-12-30 20:58:35 UTC
+++ src/common/adapter/fileDialog/FileDialogAdapterFactory.h
@@ -23,7 +23,7 @@
 #include "FileDialogAdapter.h"
 #include "SnapFileDialogAdapter.h"
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "src/common/platform/CommandRunner.h"
 #endif
 
