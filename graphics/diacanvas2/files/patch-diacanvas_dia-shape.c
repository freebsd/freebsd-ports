--- diacanvas/dia-shape.c.orig	2013-05-21 09:04:53.000000000 +0000
+++ diacanvas/dia-shape.c	2013-05-21 09:06:04.000000000 +0000
@@ -221,7 +221,8 @@ dia_shape_destroy (DiaShape *shape)
 DiaShape*
 dia_shape_ref (DiaShape *shape)
 {
-	g_return_if_fail (shape != NULL);
+	if (shape != NULL)
+		return NULL;
 
 	shape->ref_cnt++;
 
