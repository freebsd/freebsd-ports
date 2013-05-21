--- diacanvas/dia-canvas.c.orig	2007-05-15 19:26:57.000000000 +0000
+++ diacanvas/dia-canvas.c	2013-05-21 08:52:10.000000000 +0000
@@ -17,7 +17,7 @@
  * Boston, MA 02111-1307, USA.
  */
 #include <math.h>
-#include <glib/garray.h>
+#include <glib.h>
 #include <libart_lgpl/art_rect.h>
 #include <libart_lgpl/art_affine.h>
 #include <pango/pangoft2.h>
@@ -925,7 +925,8 @@ dia_canvas_redraw_views (DiaCanvas *canv
 DiaUndoManager*
 dia_canvas_get_undo_manager (DiaCanvas *canvas)
 {
-	g_return_if_fail (DIA_IS_CANVAS (canvas));
+	if (! DIA_IS_CANVAS (canvas))
+		return NULL;
 
 	return canvas->undo_manager;
 }
