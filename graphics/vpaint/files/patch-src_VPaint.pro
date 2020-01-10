--- src/VPaint.pro.orig	2020-01-07 15:06:58 UTC
+++ src/VPaint.pro
@@ -18,7 +18,5 @@
 TEMPLATE = subdirs
 
 SUBDIRS += \
-    Third/GLEW \
     Gui
 
-Gui.depends = Third/GLEW
