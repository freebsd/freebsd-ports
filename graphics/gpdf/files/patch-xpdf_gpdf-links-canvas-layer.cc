--- xpdf/gpdf-links-canvas-layer.cc.orig	Sat May 24 00:17:29 2003
+++ xpdf/gpdf-links-canvas-layer.cc	Sat May 24 00:17:46 2003
@@ -42,6 +42,8 @@
 
 BEGIN_EXTERN_C
 
+#define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
+
 struct _GPdfLinksCanvasLayerPrivate {
 	Links *links;
 };
