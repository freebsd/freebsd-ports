--- ./src/core/RSettings.cpp.orig	2013-08-06 17:32:09.000000000 +0200
+++ ./src/core/RSettings.cpp	2013-08-09 15:25:25.000000000 +0200
@@ -92,9 +92,13 @@
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
