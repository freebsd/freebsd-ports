--- ../mumble-1.2.3/src/mumble11x/mumble11x.pro	2011-02-19 16:35:18.000000000 -0500
+++ src/mumble11x/mumble11x.pro	2011-02-27 21:36:36.000000000 -0500
@@ -113,7 +113,17 @@
 
   CONFIG *= link_pkgconfig
 
-  PKGCONFIG *= openssl ogg
+  PKGCONFIG *= ogg
+
+  contains(UNAME, FreeBSD) {
+    CONFIG *= oss
+    HEADERS *= GlobalShortcut_unix.h
+    SOURCES *= GlobalShortcut_unix.cpp
+    LIBS *= -lssl
+  } else {
+    PKGCONFIG *= openssl
+  }
+
   macx {
     TARGET = Mumble11x
     ICON = ../../icons/mumble.icns
