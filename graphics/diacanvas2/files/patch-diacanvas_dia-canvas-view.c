--- diacanvas/dia-canvas-view.c.orig	2013-05-21 09:07:50.000000000 +0000
+++ diacanvas/dia-canvas-view.c	2013-05-21 09:09:40.000000000 +0000
@@ -1024,7 +1024,8 @@
 DiaTool*
 dia_canvas_view_get_tool (DiaCanvasView *view)
 {
-	g_return_if_fail (DIA_IS_CANVAS_VIEW (view));
+	if (!DIA_IS_CANVAS_VIEW (view))
+		return NULL;	
 
 	return view->tool;
 }
@@ -1065,7 +1066,8 @@
 DiaTool*
 dia_canvas_view_get_default_tool (DiaCanvasView *view)
 {
-	g_return_if_fail (DIA_IS_CANVAS_VIEW (view));
+	if (!DIA_IS_CANVAS_VIEW (view))
+		return NULL;
 
 	return view->default_tool;
 }
