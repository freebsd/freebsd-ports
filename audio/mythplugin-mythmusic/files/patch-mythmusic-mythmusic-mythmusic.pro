--- mythmusic/mythmusic/mythmusic.pro.orig	2009-08-23 00:34:03.000000000 +0200
+++ mythmusic/mythmusic/mythmusic.pro	2010-03-07 10:48:10.000000000 +0100
@@ -61,6 +61,11 @@
 SOURCES += playlistcontainer.cpp
 SOURCES += mythlistview-qt3.cpp mythlistbox-qt3.cpp
 
+freebsd {
+    INCLUDEPATH -= /usr/local/include
+    INCLUDEPATH = $$INCLUDEPATH /usr/local/include
+}
+
 macx {
     SOURCES -= cddecoder.cpp
     SOURCES += cddecoder-darwin.cpp
