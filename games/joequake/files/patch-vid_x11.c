--- vid_x11.c.orig	Mon Oct 17 10:08:06 2005
+++ vid_x11.c	Sun Jan 15 01:55:33 2006
@@ -1052,3 +1052,13 @@
 void VID_UnlockBuffer (void)
 {
 }
+
+#if !id386
+void R_Surf8Patch ()
+{
+}
+
+void R_SurfacePatch (void)
+{
+}
+#endif
