--- src/support/widgets/gtkcellrendererpixmap.h.orig	2002-12-13 12:02:45.000000000 +0100
+++ src/support/widgets/gtkcellrendererpixmap.h	2009-04-19 13:58:55.000000000 +0200
@@ -32,11 +32,11 @@
 
 
 #define GTK_TYPE_CELL_RENDERER_PIXMAP			    (gtk_cell_renderer_pixmap_get_type ())
-#define GTK_CELL_RENDERER_PIXMAP(obj)			    (GTK_CHECK_CAST ((obj), GTK_TYPE_CELL_RENDERER_PIXMAP, GtkCellRendererPixmap))
-#define GTK_CELL_RENDERER_PIXMAP_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GTK_TYPE_CELL_RENDERER_PIXMAP, GtkCellRendererPixmapClass))
-#define GTK_IS_CELL_RENDERER_PIXMAP(obj)		    (GTK_CHECK_TYPE ((obj), GTK_TYPE_CELL_RENDERER_PIXMAP))
-#define GTK_IS_CELL_RENDERER_PIXMAP_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GTK_TYPE_CELL_RENDERER_PIXMAP))
-#define GTK_CELL_RENDERER_PIXMAP_GET_CLASS(obj)  (GTK_CHECK_GET_CLASS ((obj), GTK_TYPE_CELL_RENDERER_PIXMAP, GtkCellRendererPixmapClass))
+#define GTK_CELL_RENDERER_PIXMAP(obj)			    (G_TYPE_CHECK_CLASS_CAST ((obj), GTK_TYPE_CELL_RENDERER_PIXMAP, GtkCellRendererPixmap))
+#define GTK_CELL_RENDERER_PIXMAP_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_CELL_RENDERER_PIXMAP, GtkCellRendererPixmapClass))
+#define GTK_IS_CELL_RENDERER_PIXMAP(obj)		    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_CELL_RENDERER_PIXMAP))
+#define GTK_IS_CELL_RENDERER_PIXMAP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_CELL_RENDERER_PIXMAP))
+#define GTK_CELL_RENDERER_PIXMAP_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_CELL_RENDERER_PIXMAP, GtkCellRendererPixmapClass))
 
     typedef struct GtkCellRendererPixmap_Tag GtkCellRendererPixmap;
     typedef struct GtkCellRendererPixmapClass_Tag GtkCellRendererPixmapClass;
@@ -66,7 +66,7 @@
 	void            (*_gtk_reserved4) (void);
     };
 
-    GtkType         gtk_cell_renderer_pixmap_get_type (void);
+    GType         gtk_cell_renderer_pixmap_get_type (void);
     GtkCellRenderer *gtk_cell_renderer_pixmap_new (void);
 
 #ifdef __cplusplus
