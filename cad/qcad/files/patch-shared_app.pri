--- shared_app.pri.orig	2019-05-04 22:28:42 UTC
+++ shared_app.pri
@@ -15,8 +15,8 @@ LIBS += \
 
 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -lopenNURBS \
+        -lz
 }
 
 win32 {
