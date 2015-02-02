--- src/core/RS.cpp.orig	2015-01-30 18:11:57.235513076 +0100
+++ src/core/RS.cpp	2015-01-30 18:12:23.988630795 +0100
@@ -119,4 +119,8 @@
     */
 
+#ifdef Q_OS_FREEBSD
+    dirList.append("%%DATADIR%%/" + subDirectory);
+#endif
+
     // Individual directories:
     /*
