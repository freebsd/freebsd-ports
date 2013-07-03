--- src/mumble/mumble.pro.orig	2013-06-04 11:46:38.900573055 -0500
+++ src/mumble/mumble.pro	2013-06-04 11:47:41.836576507 -0500
@@ -161,7 +161,16 @@
 
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
