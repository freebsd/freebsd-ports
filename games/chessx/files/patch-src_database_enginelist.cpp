--- src/database/enginelist.cpp_orig	2013-03-24 11:48:27.000000000 +0100
+++ src/database/enginelist.cpp	2013-03-24 11:48:59.000000000 +0100
@@ -50,7 +50,12 @@
     QString path1 = path + "/engines-linux/uci";
     QString path2 = path + "/engines-linux/winboard";
 #endif
-
+ 
+#ifdef Q_OS_FREEBSD
+    QString path1 = path + "/engines-freebsd/uci";
+    QString path2 = path + "/engines-freebsd/winboard";
+#endif
+ 
     restoreEmptyFromPath(path1, EngineData::UCI);
     restoreEmptyFromPath(path2, EngineData::WinBoard);
 }
