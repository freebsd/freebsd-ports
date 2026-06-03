--- src/core/RSettings.cpp.orig	2026-05-06 14:27:07 UTC
+++ src/core/RSettings.cpp
@@ -397,9 +397,13 @@ QString RSettings::getApplicationPath() {
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
