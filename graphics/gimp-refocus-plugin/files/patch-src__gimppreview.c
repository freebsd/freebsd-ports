--- src/gimppreview.c	2014-03-27 20:00:17.000000000 -0300
+++ src/gimppreview.c	2014-03-27 20:00:38.000000000 -0300
@@ -36,18 +36,18 @@
 #include "gimppreview.h"
 
 
-static void gimp_preview_init (GimpPreview * preview);
-static void gimp_preview_class_init (GimpPreviewClass * klass);
+static void gimp_preview_init (myGimpPreview * preview);
+static void gimp_preview_class_init (myGimpPreviewClass * klass);
 
 static void gimp_preview_plus_callback (GtkWidget * widget, gpointer data);
 static void gimp_preview_minus_callback (GtkWidget * widget, gpointer data);
 static gint gimp_preview_event (GtkWidget * widget, GdkEvent * event,
                                 gpointer data);
-static void gimp_preview_recompute_sizes (GimpPreview * preview,
+static void gimp_preview_recompute_sizes (myGimpPreview * preview,
                                           gdouble newscale);
-static void gimp_preview_update_preview (GimpPreview * preview);
+static void gimp_preview_update_preview (myGimpPreview * preview);
 
-static void gimp_preview_image_set_size (GimpPreview * preview, gint width,
+static void gimp_preview_image_set_size (myGimpPreview * preview, gint width,
                                          gint height);
 static void gimp_preview_size_request (GtkWidget * widget,
                                        GtkRequisition * requisition);
@@ -58,7 +58,7 @@
                                  GtkCallback callback,
                                  gpointer callback_data);
 gboolean gimp_preview_update_preview_idle_fun (gpointer data);
-void gimp_preview_schedule_update (GimpPreview * preview);
+void gimp_preview_schedule_update (myGimpPreview * preview);
 
 #define PROGRESS_BAR_HEIGHT (10)
 #define PREVIEW_SIZE (100)
@@ -94,11 +94,11 @@
 
 
 /*
- * Apps which use a GimpPreview widget should not be accessing the private
+ * Apps which use a myGimpPreview widget should not be accessing the private
  * data!
  */
 #define PREVIEW_DATA(preview) \
-        ((GimpPreviewData*)(GIMP_PREVIEW (preview)->private_data))
+        ((myGimpPreviewData*)(MY_GIMP_PREVIEW (preview)->private_data))
 
 typedef struct
 {
@@ -126,7 +126,7 @@
   GtkWidget *image;
   GtkWidget *progress_bar;
 }
-GimpPreviewData;
+myGimpPreviewData;
 
 
 /* Convert coordinate in preview space to image coordinates */
@@ -155,20 +155,20 @@
   if (!preview_type)
     {
       GTypeInfo preview_info = {
-        sizeof (GimpPreviewClass),
+        sizeof (myGimpPreviewClass),
         (GBaseInitFunc) NULL,
         (GBaseFinalizeFunc) NULL,
         (GClassInitFunc) gimp_preview_class_init,
         (GClassFinalizeFunc) NULL,
         (gconstpointer) NULL,   /* class_data */
-        sizeof (GimpPreview),
+        sizeof (myGimpPreview),
         0,                      /* n_preallocs */
         (GInstanceInitFunc) gimp_preview_init,
         (GTypeValueTable *) NULL /* value_table */
       };
 
       preview_type =
-        g_type_register_static (GTK_TYPE_CONTAINER, "GimpPreview",
+        g_type_register_static (GTK_TYPE_CONTAINER, "myGimpPreview",
                                 &preview_info, 0);
     }
 
@@ -181,7 +181,7 @@
  * by GTK's internal mechanisms.
  */
 static void
-gimp_preview_class_init (GimpPreviewClass * klass)
+gimp_preview_class_init (myGimpPreviewClass * klass)
 {
   GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
   GtkContainerClass *container_class = GTK_CONTAINER_CLASS (klass);
@@ -190,7 +190,7 @@
     g_signal_new ("update_preview",
                   G_TYPE_FROM_CLASS (klass),
                   G_SIGNAL_RUN_FIRST,
-                  G_STRUCT_OFFSET (GimpPreviewClass, update_preview),
+                  G_STRUCT_OFFSET (myGimpPreviewClass, update_preview),
                   NULL,
                   NULL,
                   g_cclosure_marshal_VOID__POINTER,
@@ -200,7 +200,7 @@
     g_signal_new ("preview_changed",
                   G_TYPE_FROM_CLASS (klass),
                   G_SIGNAL_RUN_FIRST,
-                  G_STRUCT_OFFSET (GimpPreviewClass, preview_changed),
+                  G_STRUCT_OFFSET (myGimpPreviewClass, preview_changed),
                   NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
 
   klass->update_preview = NULL;
@@ -212,7 +212,7 @@
 
 
 void
-gimp_preview_set_scale_amount(GimpPreview *preview, gdouble scale_amount)
+gimp_preview_set_scale_amount(myGimpPreview *preview, gdouble scale_amount)
 {
   /*
    * If the caller wants to set the scale amount, let them do so.
@@ -269,7 +269,7 @@
  * by GTK's internal mechanisms.
  */
 static void
-gimp_preview_init (GimpPreview * preview)
+gimp_preview_init (myGimpPreview * preview)
 {
   gchar buffer[10];
 
@@ -277,7 +277,7 @@
   GTK_WIDGET_SET_FLAGS (preview, GTK_NO_WINDOW);
   GTK_CONTAINER (preview)->resize_mode = GTK_RESIZE_IMMEDIATE;
 
-  preview->private_data = g_malloc0 (sizeof (GimpPreviewData));
+  preview->private_data = g_malloc0 (sizeof (myGimpPreviewData));
 
 
   PREVIEW_DATA (preview)->label = gtk_label_new ("");
@@ -307,7 +307,7 @@
 gimp_preview_new_with_args (GimpDrawable * drawable, gint cb_preview_size,
                             gdouble cb_scale_amount, gint cb_allow_scale)
 {
-  GimpPreview *preview;
+  myGimpPreview *preview;
   GtkWidget *frame;
   GtkWidget *hbox;
   GtkWidget *event_box;
@@ -337,14 +337,14 @@
 
 
   /* Now allocate the actual preview window. */
-  preview = GIMP_PREVIEW (g_object_new (gimp_preview_get_type (), NULL));
+  preview = MY_GIMP_PREVIEW (g_object_new (gimp_preview_get_type (), NULL));
 
   /* Set the scale amount. */
   gimp_preview_set_scale_amount(preview, cb_scale_amount);
 
   /* Save the drawable info. */
   preview->drawable = drawable;
-  preview->drawable_has_alpha = gimp_drawable_has_alpha (drawable->id);
+  preview->drawable_has_alpha = gimp_drawable_has_alpha (drawable->drawable_id);
 
   /* Calculate our preview size. */
   if (preview_size == PREVIEW_FIXED_SIZE)
@@ -352,8 +352,8 @@
       preview_width = i2p (drawable->width, preview->scale);
       preview_height = i2p (drawable->height, preview->scale);
 
-      GIMP_PREVIEW (preview)->width = preview_width;
-      GIMP_PREVIEW (preview)->height = preview_height;
+      MY_GIMP_PREVIEW (preview)->width = preview_width;
+      MY_GIMP_PREVIEW (preview)->height = preview_height;
     }
   else
     {
@@ -454,7 +454,7 @@
 static void
 gimp_preview_size_request (GtkWidget * widget, GtkRequisition * requisition)
 {
-  GimpPreview *preview = GIMP_PREVIEW (widget);
+  myGimpPreview *preview = MY_GIMP_PREVIEW (widget);
   GtkRequisition resize_box_requisition;
 
 #ifdef PREVIEW_DEBUG
@@ -478,7 +478,7 @@
 static void
 gimp_preview_size_allocate (GtkWidget * widget, GtkAllocation * allocation)
 {
-  GimpPreview *preview = GIMP_PREVIEW (widget);
+  myGimpPreview *preview = MY_GIMP_PREVIEW (widget);
   GtkAllocation resize_box_allocation, progress_bar_allocation,
     event_box_allocation;
   GtkRequisition resize_box_requisition;
@@ -543,7 +543,7 @@
                      gboolean include_internals,
                      GtkCallback callback, gpointer callback_data)
 {
-  GimpPreview *preview = GIMP_PREVIEW (container);
+  myGimpPreview *preview = MY_GIMP_PREVIEW (container);
 
   if (PREVIEW_DATA (preview)->resize_box)
     {
@@ -564,7 +564,7 @@
  * Plug-ins call this to do an update of the preview area.
  */
 void
-gimp_preview_update (GimpPreview * preview)
+gimp_preview_update (myGimpPreview * preview)
 {
   gimp_preview_recompute_sizes (preview, preview->scale);
   gimp_preview_update_preview (preview);
@@ -579,11 +579,11 @@
 static void
 gimp_preview_plus_callback (GtkWidget * widget, gpointer data)
 {
-  GimpPreview *preview;
+  myGimpPreview *preview;
   gchar buffer[10];
   gdouble new_scale;
 
-  preview = GIMP_PREVIEW (data);
+  preview = MY_GIMP_PREVIEW (data);
   if (PREVIEW_DATA (preview)->scale_n == PREVIEW_SCALE_LAST)
     return;
 
@@ -616,11 +616,11 @@
 static void
 gimp_preview_minus_callback (GtkWidget * widget, gpointer data)
 {
-  GimpPreview *preview;
+  myGimpPreview *preview;
   gchar buffer[10];
   gdouble new_scale;
 
-  preview = GIMP_PREVIEW (data);
+  preview = MY_GIMP_PREVIEW (data);
   if (PREVIEW_DATA (preview)->scale_n == 0)
     return;
 
@@ -651,12 +651,12 @@
 static gint
 gimp_preview_event (GtkWidget * widget, GdkEvent * event, gpointer data)
 {
-  GimpPreview *preview;
+  myGimpPreview *preview;
   GdkEventButton *button_event;
   gint x, y;
   gint dx, dy;
 
-  preview = GIMP_PREVIEW (data);
+  preview = MY_GIMP_PREVIEW (data);
   button_event = (GdkEventButton *) event;
 
   switch (event->type)
@@ -733,7 +733,7 @@
  * This function is also used for initializing the preview.
  */
 static void
-gimp_preview_recompute_sizes (GimpPreview * preview, gdouble new_scale)
+gimp_preview_recompute_sizes (myGimpPreview * preview, gdouble new_scale)
 {
 
   /* The center of the preview in image coordinates.
@@ -765,7 +765,7 @@
 }
 
 void
-gimp_preview_generate_update_event (GimpPreview * preview)
+gimp_preview_generate_update_event (myGimpPreview * preview)
      /* Signal the user that the preview must be updated */
 {
   const gdouble scale = preview->scale;
@@ -783,7 +783,7 @@
            0,
            preview->drawable->height - image_y);
 
-  GimpPreviewEvent preview_event;
+  myGimpPreviewEvent preview_event;
 
   preview_event.event_id = PREVIEW_DATA (preview)->current_event_id;
   preview_event.scale = preview->scale;
@@ -814,7 +814,7 @@
  * to step through source and destination!
  */
 static void
-gimp_preview_update_preview (GimpPreview * preview)
+gimp_preview_update_preview (myGimpPreview * preview)
 {
   GimpPixelRgn region;
   guchar *image_data = NULL;
@@ -1012,7 +1012,7 @@
 
 
 void
-gimp_preview_force_redraw (GimpPreview * preview)
+gimp_preview_force_redraw (myGimpPreview * preview)
 {
   gtk_widget_queue_draw (GTK_WIDGET (PREVIEW_DATA (preview)->image));
 }
@@ -1022,7 +1022,7 @@
 gboolean
 gimp_preview_update_preview_idle_fun (gpointer data)
 {
-  GimpPreview *preview = GIMP_PREVIEW (data);
+  myGimpPreview *preview = MY_GIMP_PREVIEW (data);
   gint event_id = PREVIEW_DATA (preview)->current_event_id;
 
 #ifdef PREVIEW_DEBUG
@@ -1041,7 +1041,7 @@
 }
 
 void
-gimp_preview_schedule_update (GimpPreview * preview)
+gimp_preview_schedule_update (myGimpPreview * preview)
 {
   PREVIEW_DATA (preview)->current_event_id++;
 
@@ -1082,7 +1082,7 @@
 }
 
 void
-gimp_preview_image_set_size (GimpPreview * preview, gint width, gint height)
+gimp_preview_image_set_size (myGimpPreview * preview, gint width, gint height)
 {
   const gint real_width = MIN (preview->max_width, width);
   const gint real_height = MIN (preview->max_height, height);
@@ -1120,8 +1120,8 @@
 
 /**
  * gimp_preview_draw_row:
- * @preview: the #GimpPreview
- * @event_id: event_id that was sent with the #GimpPreviewEvent.
+ * @preview: the #myGimpPreview
+ * @event_id: event_id that was sent with the #myGimpPreviewEvent.
  * @type: the format of the data (e.g. %GIMP_RGBA_IMAGE).
  * @row:the relative number of the row within the preview.
  * The top row of the preview is number 0.
@@ -1137,7 +1137,7 @@
  * with the same event-id will be ignored by the preview.
  **/
 gboolean
-gimp_preview_draw_row (GimpPreview * preview, const gint event_id,
+gimp_preview_draw_row (myGimpPreview * preview, const gint event_id,
                        GimpImageType type, gint row,
                        const guchar * const data)
 {
@@ -1247,8 +1247,8 @@
 
 /**
  * gimp_preview_draw_unscaled_row:
- * @preview: the #GimpPreview
- * @event_id: event_id that was sent with the #GimpPreviewEvent.
+ * @preview: the #myGimpPreview
+ * @event_id: event_id that was sent with the #myGimpPreviewEvent.
  * @type: the format of the data (e.g. %GIMP_RGBA_IMAGE).
  * @row:row is the relative position of the row w.r.t. preview_event->image_y.
  * The top row has number 0.
@@ -1267,7 +1267,7 @@
  * with the same event-id will be ignored by the preview.
  **/
 gboolean
-gimp_preview_draw_unscaled_row (GimpPreview * preview, const gint event_id,
+gimp_preview_draw_unscaled_row (myGimpPreview * preview, const gint event_id,
                                 GimpImageType type, const gint row,
                                 const guchar * const data)
 {
@@ -1445,8 +1445,8 @@
 
 /**
  * gimp_preview_progress_set_fraction:
- * @preview: the #GimpPreview.
- * @event_id: event_id that was sent with the #GimpPreviewEvent.
+ * @preview: the #myGimpPreview.
+ * @event_id: event_id that was sent with the #myGimpPreviewEvent.
  * @fraction: the fraction completed.
  *
  * Set the progress bar of the preview to @fraction completed.
@@ -1456,7 +1456,7 @@
  * with the same event-id will be ignored by the preview.
  **/
 gboolean
-gimp_preview_progress_set_fraction (GimpPreview * preview,
+gimp_preview_progress_set_fraction (myGimpPreview * preview,
                                     const gint event_id, double fraction)
 {
   const gboolean return_status =
