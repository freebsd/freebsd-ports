--- src/core/RSettings.cpp.orig	2019-12-23 11:24:24 UTC
+++ src/core/RSettings.cpp
@@ -363,9 +363,13 @@ QString RSettings::getApplicationPath() {
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
