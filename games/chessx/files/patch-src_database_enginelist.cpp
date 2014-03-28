--- src/database/enginelist.cpp_orig	2014-03-21 10:38:05.774005768 +0100
+++ src/database/enginelist.cpp	2014-03-21 10:38:46.470001992 +0100
@@ -52,6 +52,14 @@
     restoreEmptyFromPath(path1, EngineData::UCI);
     restoreEmptyFromPath(path2, EngineData::WinBoard);
 #endif
+
+#ifdef Q_OS_FREEBSD
+    QString path(AppSettings->programDataPath());
+    QString path1 = path + "/engines-freebsd/uci";
+    QString path2 = path + "/engines-freebsd/winboard";
+    restoreEmptyFromPath(path1, EngineData::UCI);
+    restoreEmptyFromPath(path2, EngineData::WinBoard);
+#endif 
 }
 
 void EngineList::restore()
