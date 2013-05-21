--- diacanvas/dia-canvas-editable.c.orig	2013-05-21 08:56:55.000000000 +0000
+++ diacanvas/dia-canvas-editable.c	2013-05-21 08:59:33.000000000 +0000
@@ -103,7 +103,8 @@ dia_canvas_editable_base_init (gpointer 
 gboolean
 dia_canvas_editable_is_editable (DiaCanvasEditable *editable)
 {
-	g_return_if_fail (DIA_IS_CANVAS_EDITABLE (editable));
+	if (!DIA_IS_CANVAS_EDITABLE (editable))
+		return FALSE;
 	
 	if (!DIA_CANVAS_EDITABLE_GET_IFACE (editable)->is_editable)
 		return TRUE;
@@ -115,7 +116,8 @@ DiaShapeText*
 dia_canvas_editable_get_editable_shape (DiaCanvasEditable *editable,
 					gdouble x, gdouble y)
 {
-	g_return_if_fail (DIA_IS_CANVAS_EDITABLE (editable));
+	if (!DIA_IS_CANVAS_EDITABLE (editable))
+		return NULL;
 	
 	if (!DIA_CANVAS_EDITABLE_GET_IFACE (editable)->get_editable_shape) {
 		g_warning ("DiaCanvasEditable::get_editable_shape not "
