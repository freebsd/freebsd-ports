--- Sketch/Modules/skcolor.c.orig	Wed Oct  6 23:46:00 1999
+++ Sketch/Modules/skcolor.c	Mon Sep 11 19:35:33 2000
@@ -484,10 +484,14 @@
 	}
 	PyMem_DEL(self->dither_matrix);
     }
-    PyMem_XDEL(self->dither_red);
-    PyMem_XDEL(self->dither_green);
-    PyMem_XDEL(self->dither_blue);
-    PyMem_XDEL(self->dither_gray);
+    if (self->dither_red)
+	PyMem_DEL(self->dither_red);
+    if (self->dither_green)
+	PyMem_DEL(self->dither_green);
+    if (self->dither_blue)
+	PyMem_DEL(self->dither_blue);
+    if (self->dither_gray)
+	PyMem_DEL(self->dither_gray);
 }
 
 static int
