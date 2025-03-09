--- shared_app.pri.orig	2025-02-10 09:29:49 UTC
+++ shared_app.pri
@@ -18,8 +18,8 @@ LIBS += \
 
 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -lopenNURBS \
+        -lz
 }
 
 win32 {
