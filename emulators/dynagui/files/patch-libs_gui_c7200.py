--- libs/gui_c7200.py.orig	2009-02-09 14:29:55.000000000 -0500
+++ libs/gui_c7200.py	2009-02-09 14:30:28.000000000 -0500
@@ -412,7 +412,7 @@
 
 class GuiC7200(C7200, GuiRouter):
     pixmap = cairo.ImageSurface.create_from_png(
-                    os.path.join('img', 'chassis.png'))
+                    os.path.join('/usr/local/share/dynagui/img', 'chassis.png'))
 
     def __init__(self, dynamips, x=10, y=10, name=None):
         GuiRouter.__init__(self, x, y)
