--- src/core/RSettings.cpp.orig	2025-02-10 09:29:49 UTC
+++ src/core/RSettings.cpp
@@ -393,9 +393,13 @@ QString RSettings::getApplicationPath() {
     }
 #endif
 
+#ifdef Q_OS_FREEBSD
+	ret.cd("/usr/local/share/qcad");
+#else
     if (ret.dirName() == "debug" || ret.dirName() == "release") {
         ret.cdUp();
     }
+#endif
 
     return ret.path();
 }
