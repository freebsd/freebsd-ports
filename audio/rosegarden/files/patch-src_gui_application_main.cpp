--- src/gui/application/main.cpp.orig	2016-02-29 12:18:01 UTC
+++ src/gui/application/main.cpp
@@ -359,6 +359,11 @@ void usage()
     exit(2);
 }
 
+#ifdef __GNUG__
+#pragma GCC push
+#pragma GCC diagnostic ignored "-Wunused-variable"
+#endif
+
 int main(int argc, char *argv[])
 {
 
@@ -405,7 +410,6 @@ int main(int argc, char *argv[])
     // (this has to be outside the ifdef block below)
     QSettings preAppSettings("rosegardenmusic", "Rosegarden");
     preAppSettings.beginGroup(GeneralOptionsConfigGroup);
-#pragma GCC diagnostic ignored "-Wunused-variable"
     unsigned int graphicsSystem = preAppSettings.value("graphics_system", Native).toUInt();
     preAppSettings.endGroup();
 
@@ -868,4 +872,7 @@ int main(int argc, char *argv[])
 
     return returnCode;
 }
+#ifdef __GNUG__
+#pragma GCC pop
+#endif
 
