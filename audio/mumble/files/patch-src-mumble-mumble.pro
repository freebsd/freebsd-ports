--- src/mumble/mumble.pro.orig	2009-03-16 16:21:13.038835100 +0100
+++ src/mumble/mumble.pro	2009-03-16 16:22:07.155100994 +0100
@@ -107,6 +107,13 @@
     SOURCES *= GlobalShortcut_unix.cpp TextToSpeech_unix.cpp Overlay_unix.cpp
   }
 
+  contains(UNAME, FreeBSD) {
+    CONFIG *= oss
+    HEADERS *= GlobalShortcut_unix.h
+    SOURCES *= GlobalShortcut_unix.cpp TextToSpeech_unix.cpp Overlay_unix.cpp
+    LIBS *= -lssl
+  }
+
   macx {
     TARGET = Mumble
     ICON = ../../icons/mumble.icns
