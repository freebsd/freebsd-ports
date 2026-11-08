--- src/core/RSettings.cpp.orig	2026-08-26 20:00:19 UTC
+++ src/core/RSettings.cpp
@@ -405,9 +405,13 @@ QString RSettings::getApplicationPath() {
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
