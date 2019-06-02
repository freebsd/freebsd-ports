--- src/core/RSettings.cpp.orig	2019-05-01 14:25:33 UTC
+++ src/core/RSettings.cpp
@@ -346,9 +346,13 @@ QString RSettings::getApplicationPath() {
     }
 #endif
 
+#ifdef Q_OS_FREEBSD
+	ret.cd("%%DATADIR%%");
+#else
     if (ret.dirName() == "debug" || ret.dirName() == "release") {
         ret.cdUp();
     }
+#endif
 
     return ret.path();
 }
