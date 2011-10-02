--- ./src/common/FindFile.cpp.orig	2010-02-17 19:59:26.000000000 +0300
+++ ./src/common/FindFile.cpp	2011-10-01 19:06:16.000000000 +0400
@@ -456,6 +456,10 @@
 	AddToFileList(&basesearchpaths, "${HOME}/OpenLieroX");
 	AddToFileList(&basesearchpaths, ".");
 	AddToFileList(&basesearchpaths, "${BIN}");
+#elif defined(__FreeBSD__)
+	AddToFileList(&basesearchpaths, "${HOME}/.OpenLieroX");
+	AddToFileList(&basesearchpaths, ".");
+	AddToFileList(&basesearchpaths, SYSTEM_DATA_DIR);
 #else // all other systems (Linux, *BSD, OS/2, ...)
 	AddToFileList(&basesearchpaths, "${HOME}/.OpenLieroX");
 	AddToFileList(&basesearchpaths, ".");
