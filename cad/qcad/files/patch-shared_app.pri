--- shared_app.pri.orig	2013-08-06 17:32:09.000000000 +0200
+++ shared_app.pri	2013-08-08 15:33:45.000000000 +0200
@@ -15,8 +15,8 @@
 
 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -lopenNURBS \
+        -lz
 }
 
 win32 {
