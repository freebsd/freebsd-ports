--- src/common/global/pfile.cpp.orig
+++ src/common/global/pfile.cpp
@@ -99,9 +99,14 @@
 {
   close();
   _tmp.reset(new KTemporaryFile);
+#if defined(NO_KDE)
+  _tmp->setFileTemplate(QLatin1String("XXXXXX") + _extension);
+  _tmp->setAutoRemove(true);
+#else
   if (!_extension.isEmpty()) {
     _tmp->setSuffix("." + _extension);
   }
+#endif
   if (!_tmp->open()) {
     _error = i18n("Could not create temporary file.");
     _log.sorry(_error, i18n("File: %1").arg(_tmp->name()));
@@ -149,9 +154,14 @@
     }
 
     _tmp.reset(new KTemporaryFile);
+#if defined(NO_KDE)
+    _tmp->setFileTemplate(QLatin1String("XXXXXX") + _extension);
+    _tmp->setAutoRemove(true);
+#else
     if (!_extension.isEmpty()) {
       _tmp->setSuffix("." + _extension);
     }
+#endif
     if (!_tmp->open()) {
       _error = i18n("Could not create temporary file.");
       _log.sorry(_error, i18n("File: %1").arg(_tmp->name()));
