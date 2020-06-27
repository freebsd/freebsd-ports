--- app.pri.orig	2020-06-22 11:24:05 UTC
+++ app.pri
@@ -15,7 +15,7 @@ else{
 LIBS += -lcommonui -lqvge -lqvgeio -lqtpropertybrowser -lqsint-widgets
 
 USE_OGDF{
-    LIBS += -logdf
+    LIBS += -lOGDF
 }
 
 win32{
@@ -24,7 +24,8 @@ win32{
 
 unix{
     !haiku{
-        LIBS += -lQt5X11Extras -lX11
+        QT += x11extras
+        LIBS += -lX11
     }
 }
 
