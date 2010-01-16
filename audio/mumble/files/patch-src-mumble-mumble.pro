--- src/mumble/mumble.pro.orig	2010-01-08 00:37:46.000000000 +0200
+++ src/mumble/mumble.pro	2010-01-10 23:59:44.000000000 +0200
@@ -44,7 +44,11 @@
 }
 
 CONFIG(no-bundled-celt) {
-  INCLUDEPATH	*= /usr/include/celt
+  contains(UNAME, FreeBSD) {
+    INCLUDEPATH	*= /usr/local/include/celt
+  } else {
+    INCLUDEPATH	*= /usr/include/celt
+  }
 }
 
 !CONFIG(no-bundled-celt) {
@@ -110,7 +114,16 @@
 
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
 
   contains(UNAME, Linux) {
     !CONFIG(no-oss) {
