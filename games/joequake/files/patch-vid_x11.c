--- ./vid_x11.c.orig	Sat Mar 25 15:28:06 2006
+++ ./vid_x11.c	Sat May 20 10:00:24 2006
@@ -1053,3 +1053,13 @@
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
