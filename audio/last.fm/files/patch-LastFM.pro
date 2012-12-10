--- LastFM.pro.orig	2012-12-02 14:23:24.000000000 +0100
+++ LastFM.pro	2012-12-02 14:23:37.000000000 +0100
@@ -37,7 +37,7 @@
     SUBDIRS -= src/mediadevices/ipod
 }
 
-linux* {
+unix:!mac* {
     SUBDIRS -= src/Twiddly \
                src/Bootstrapper/ITunesDevice
 
