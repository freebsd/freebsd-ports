--- LastFM.pro.orig	2010-09-20 10:43:11 UTC
+++ LastFM.pro
@@ -37,7 +37,7 @@ mac {
     SUBDIRS -= src/mediadevices/ipod
 }
 
-linux* {
+unix:!mac* {
     SUBDIRS -= src/Twiddly \
                src/Bootstrapper/ITunesDevice
 
