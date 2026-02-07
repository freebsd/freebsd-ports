--- src/gimppreview.h	2014-03-27 20:00:17.000000000 -0300
+++ src/gimppreview.h	2014-03-27 20:00:38.000000000 -0300
@@ -32,25 +32,25 @@
 
 #define PREVIEW_FIXED_SIZE           0
 #define PREVIEW_DEFAULT_SIZE         -1
-#define GIMP_TYPE_PREVIEW            (gimp_preview_get_type ())
-#define GIMP_PREVIEW(obj)            (GTK_CHECK_CAST ((obj), GIMP_TYPE_PREVIEW, GimpPreview))
-#define GIMP_PREVIEW_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GIMP_TYPE_PREVIEW, GimpPreviewClass))
-#define GIMP_IS_PREVIEW(obj)         (GTK_CHECK_TYPE ((obj), GIMP_TYPE_PREVIEW))
-#define GIMP_IS_PREVIEW_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_PREVIEW))
-typedef struct _GimpPreview GimpPreview;
-typedef struct _GimpPreviewClass GimpPreviewClass;
-typedef struct _GimpPreviewEvent GimpPreviewEvent;
+//#define GIMP_TYPE_PREVIEW            (gimp_preview_get_type ())
+#define MY_GIMP_PREVIEW(obj)            (GTK_CHECK_CAST ((obj), GIMP_TYPE_PREVIEW, myGimpPreview))
+#define MY_GIMP_PREVIEW_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GIMP_TYPE_PREVIEW, myGimpPreviewClass))
+//#define GIMP_IS_PREVIEW(obj)         (GTK_CHECK_TYPE ((obj), GIMP_TYPE_PREVIEW))
+//#define GIMP_IS_PREVIEW_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_PREVIEW))
+typedef struct _myGimpPreview myGimpPreview;
+typedef struct _myGimpPreviewClass myGimpPreviewClass;
+typedef struct _myGimpPreviewEvent myGimpPreviewEvent;
 
-struct _GimpPreviewClass
+struct _myGimpPreviewClass
 {
   GtkContainerClass parent_class;
 
-  void (*update_preview) (GimpPreview * preview, GimpPreviewEvent * event);
-  void (*preview_changed) (GimpPreview * preview);
+  void (*update_preview) (myGimpPreview * preview, myGimpPreviewEvent * event);
+  void (*preview_changed) (myGimpPreview * preview);
 };
 
 
-struct _GimpPreview
+struct _myGimpPreview
 {
   GtkContainer parent;
 
@@ -75,13 +75,13 @@
 };
 
 /**
- * GimpPreviewEvent:
+ * myGimpPreviewEvent:
  * @event_id: Id of this event. This is needed for gimp_preview_draw_row,
  * gimp_preview_draw_unscaled_row and gimp_preview_progress_set_fraction.
  * @scale: Current scale of the preview.
  *
  **/
-struct _GimpPreviewEvent
+struct _myGimpPreviewEvent
 {
   gint event_id;                /* Id of this event */
   gdouble scale;                /* Scale of preview */
@@ -113,20 +113,20 @@
                                        gint preview_size,
                                        gdouble scale_amount,
                                        gint allow_scale);
-void gimp_preview_update (GimpPreview * preview);
+void gimp_preview_update (myGimpPreview * preview);
 
-gboolean gimp_preview_draw_row (GimpPreview * preview, const gint event_id,
+gboolean gimp_preview_draw_row (myGimpPreview * preview, const gint event_id,
                                 GimpImageType type, const gint row,
                                 const guchar * const data);
 
-gboolean gimp_preview_draw_unscaled_row (GimpPreview * preview,
+gboolean gimp_preview_draw_unscaled_row (myGimpPreview * preview,
                                          const gint event_id,
                                          GimpImageType type, const gint row,
                                          const guchar * const data);
 
-void gimp_preview_force_redraw (GimpPreview * preview);
+void gimp_preview_force_redraw (myGimpPreview * preview);
 
-gboolean gimp_preview_progress_set_fraction (GimpPreview * preview,
+gboolean gimp_preview_progress_set_fraction (myGimpPreview * preview,
                                              const gint event_id,
                                              double fraction);
 
