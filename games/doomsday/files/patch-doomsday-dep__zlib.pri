--- doomsday/dep_zlib.pri.orig	2013-11-02 07:38:18.000000000 -0700
+++ doomsday/dep_zlib.pri	2013-12-24 04:55:18.000000000 -0700
@@ -12,6 +12,10 @@
     # Mac OS X.
     LIBS += -lz
 }
+else:freebsd-* {
+    # FreeBSD
+    LIBS += -lz
+}
 else {
     # Generic Unix.
     QMAKE_CFLAGS += $$system(pkg-config zlib --cflags)
