--- shared_app.pri.orig	2015-11-28 16:39:25.396369000 +0000
+++ shared_app.pri	2015-11-28 16:41:00.193868000 +0000
@@ -18,6 +18,6 @@
 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -lopenNURBS \
+        -lz
 }
 
