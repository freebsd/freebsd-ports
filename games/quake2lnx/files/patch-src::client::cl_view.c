--- src/client/cl_view.c.orig	Thu Jun 12 14:25:46 2003
+++ src/client/cl_view.c	Thu Jun 12 14:26:07 2003
@@ -470,7 +470,9 @@
 */
 void SCR_DrawCrosshair (void)
 {
+#ifdef QMAX
   float scale;
+#endif
 	if (!crosshair->value)
 		return;
 
