--- src/Settings.h.orig	2015-08-12 08:43:33 UTC
+++ src/Settings.h
@@ -277,6 +277,7 @@ extern int OperatingSystem;
 #define LINUX   2
 #define OSX     3
 #define OPENBSD 4
+#define FREEBSD 5
 
 #if QT_VERSION > 0x050000
 #define OS_STYLE "Fusion"
