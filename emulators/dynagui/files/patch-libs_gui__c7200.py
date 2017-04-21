--- libs/gui_c7200.py.orig	2007-10-31 18:55:27 UTC
+++ libs/gui_c7200.py
@@ -412,7 +412,7 @@ class GuiC7200_IO_2FE(PA_C7200_IO_2FE):
 
 class GuiC7200(C7200, GuiRouter):
     pixmap = cairo.ImageSurface.create_from_png(
-                    os.path.join('img', 'chassis.png'))
+                    os.path.join('/usr/local/share/dynagui/img', 'chassis.png'))
 
     def __init__(self, dynamips, x=10, y=10, name=None):
         GuiRouter.__init__(self, x, y)
