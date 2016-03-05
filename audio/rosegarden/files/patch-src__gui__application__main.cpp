--- src/gui/application/main.cpp.orig	2015-12-31 13:49:35 UTC
+++ src/gui/application/main.cpp
@@ -354,6 +354,11 @@ void usage()
     exit(2);
 }
 
+#ifdef __GNUG__
+#pragma GCC push
+#pragma GCC diagnostic ignored "-Wunused-variable"
+#endif
+
 int main(int argc, char *argv[])
 {
     for (int i = 1; i < argc; ++i) {
@@ -377,7 +382,6 @@ int main(int argc, char *argv[])
     // (this has to be outside the ifdef block below)
     QSettings preAppSettings("rosegardenmusic", "Rosegarden");
     preAppSettings.beginGroup(GeneralOptionsConfigGroup);
-#pragma GCC diagnostic ignored "-Wunused-variable"
     unsigned int graphicsSystem = preAppSettings.value("graphics_system", Native).toUInt();
     preAppSettings.endGroup();
 
@@ -840,4 +844,7 @@ int main(int argc, char *argv[])
 
     return returnCode;
 }
+#ifdef __GNUG__
+#pragma GCC pop
+#endif
 
