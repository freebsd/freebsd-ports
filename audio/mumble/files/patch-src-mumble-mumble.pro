--- src/mumble/mumble.pro.orig	2014-08-08 15:51:59 UTC
+++ src/mumble/mumble.pro
@@ -161,7 +161,16 @@ unix {
 
   CONFIG *= link_pkgconfig
 
-  PKGCONFIG *= openssl sndfile
+  PKGCONFIG *= sndfile
+
+  contains(UNAME, FreeBSD) {
+    CONFIG *= oss
+    HEADERS *= GlobalShortcut_unix.h
+    SOURCES *= GlobalShortcut_unix.cpp TextToSpeech_unix.cpp Overlay_unix.cpp
+    LIBS *= -lssl
+  } else {
+    PKGCONFIG *= openssl
+  }
 
   macx {
     TARGET = Mumble
