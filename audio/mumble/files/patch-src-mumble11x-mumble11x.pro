--- src/mumble11x/mumble11x.pro.orig	2010-01-08 00:37:46.000000000 +0200
+++ src/mumble11x/mumble11x.pro	2010-01-09 21:00:31.000000000 +0200
@@ -113,7 +113,16 @@
 
   CONFIG *= link_pkgconfig
 
-  PKGCONFIG *= openssl ogg
+  PKGCONFIG *= ogg
+
+  contains(UNAME, FreeBSD) {
+    CONFIG *= oss
+    HEADERS *= GlobalShortcut_unix.h
+    SOURCES *= GlobalShortcut_unix.cpp TextToSpeech_unix.cpp Overlay_unix.cpp
+    LIBS *= -lssl
+  } else {
+    PKGCONFIG *= openssl
+  }
 
   contains(UNAME, Linux) {
     !CONFIG(no-oss) {
