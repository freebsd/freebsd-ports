--- xpdf/gpdf-link-canvas-item.cc.orig	Fri May 23 23:04:01 2003
+++ xpdf/gpdf-link-canvas-item.cc	Sat May 24 00:15:18 2003
@@ -33,6 +33,8 @@
 
 BEGIN_EXTERN_C
 
+#define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
+
 struct _GPdfLinkCanvasItemPrivate {
 	Link *link;
 };
