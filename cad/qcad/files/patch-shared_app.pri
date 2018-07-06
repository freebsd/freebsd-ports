--- shared_app.pri.orig	2018-06-19 20:32:20 UTC
+++ shared_app.pri
@@ -13,12 +13,12 @@ LIBS += \
     -l$${RLIBNAME}stemmer \
     -lstemmer \
     -l$${RLIBNAME}zip \
-    -lquazip
+    -lquazip5
 
 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -lopenNURBS \
+        -lz
 }
 
 win32 {
