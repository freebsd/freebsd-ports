--- pokerth.pro.orig	2017-08-16 12:24:03 UTC
+++ pokerth.pro
@@ -8,7 +8,7 @@ official_server {
 client: {
     SUBDIRS += pokerth_game.pro
 }
-!mac:!gui_800x480:!client:!qml-client {
+!mac:!gui_800x480:!qml-client {
     SUBDIRS += pokerth_server.pro chatcleaner.pro
 }
 
