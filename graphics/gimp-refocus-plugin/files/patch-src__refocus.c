--- src/refocus.c	2014-03-27 20:00:17.000000000 -0300
+++ src/refocus.c	2014-03-27 20:00:38.000000000 -0300
@@ -45,9 +45,9 @@
 
 /* Declare local functions. */
 static void query (void);
-static void run (char *name,
+static void run (const gchar *name,
                  gint nparams,
-                 GimpParam * param,
+                 const GimpParam * param,
                  gint * nreturn_vals, GimpParam ** return_vals);
 static gint dialog ();
 static void doit (void);
@@ -111,7 +111,6 @@
     {GIMP_PDB_FLOAT, "noise", "Noise to Signal ratio"},
   };
   static GimpParamDef *return_vals = NULL;
-  static gint nargs = (gint) (sizeof (args) / sizeof (args[0]));
   static gint nreturn_vals = 0;
 
   gimp_install_procedure ("plug_in_refocus",
@@ -123,15 +122,15 @@
                           "<Image>/Filters/Enhance/Refocus ...",
                           "RGB*, GRAY*",
                           GIMP_PLUGIN,
-                          nargs, nreturn_vals, args, return_vals);
+                          G_N_ELEMENTS(args), nreturn_vals, args, return_vals);
 }
 
 static void
-run (char *name, gint n_params, GimpParam * param,
+run (const gchar *name, gint n_params, const GimpParam * param,
      gint * nreturn_vals, GimpParam ** return_vals)
 {
   static GimpParam values[1];
-  GimpRunModeType run_mode;
+  GimpRunMode run_mode;
   GimpPDBStatusType status = GIMP_PDB_SUCCESS;
 
   (void) name;                  /* Shut up warnings about unused parameters. */
@@ -186,8 +185,8 @@
     {
 
       /*  Make sure that the drawable is gray or RGB color  */
-      if (gimp_drawable_is_rgb (drawable->id) ||
-          gimp_drawable_is_gray (drawable->id))
+      if (gimp_drawable_is_rgb (drawable->drawable_id) ||
+          gimp_drawable_is_gray (drawable->drawable_id))
         {
           doit ();
 
@@ -336,7 +335,7 @@
   (void) data;
   set_busy_cursor (widget, TRUE);
   update_matrix ();
-  gimp_preview_update (GIMP_PREVIEW (my_widgets.preview));
+  gimp_preview_update (MY_GIMP_PREVIEW (my_widgets.preview));
   set_busy_cursor (widget, FALSE);
 }
 
@@ -369,11 +368,11 @@
 {
   gint event_id = GPOINTER_TO_INT (data);
   return (gimp_preview_progress_set_fraction
-          (GIMP_PREVIEW (my_widgets.preview), event_id, arg));
+          (MY_GIMP_PREVIEW (my_widgets.preview), event_id, arg));
 }
 
 static void
-preview_callback (GtkWidget * widget, GimpPreviewEvent * event, gpointer data)
+preview_callback (GtkWidget * widget, myGimpPreviewEvent * event, gpointer data)
 {
   TileSource source;
   TileSink sink;
@@ -393,7 +392,7 @@
                                       im_width, im_height);
       tile_sink_init_for_preview (&sink, drawable, image_x, image_y,
                                   im_width, im_height);
-      gimp_preview_progress_set_fraction (GIMP_PREVIEW (my_widgets.preview),
+      gimp_preview_progress_set_fraction (MY_GIMP_PREVIEW (my_widgets.preview),
                                           event->event_id, 0);
       bd_closure_init (&update_progress_closure,
                        preview_progress_update_fun,
@@ -409,9 +408,9 @@
         {
           tile_sink_get_row (&sink, buf, image_x, image_y + row, im_width);
           event_is_current =
-            gimp_preview_draw_unscaled_row (GIMP_PREVIEW (my_widgets.preview),
+            gimp_preview_draw_unscaled_row (MY_GIMP_PREVIEW (my_widgets.preview),
                                             event->event_id,
-                                            gimp_drawable_type (drawable->id),
+                                            gimp_drawable_type (drawable->drawable_id),
                                             row, buf);
         };
       g_free (buf);
@@ -583,7 +582,7 @@
 
   gtk_widget_show (dlg);
   redraw_all ();
-  gimp_preview_update (GIMP_PREVIEW (preview));
+  gimp_preview_update (MY_GIMP_PREVIEW (preview));
   gtk_main ();
   gdk_flush ();
   return run_flag;
@@ -608,7 +607,7 @@
   gimp_progress_init ("Computing matrix");
   update_matrix ();
   gimp_progress_init ("Applying convolution");
-  gimp_drawable_mask_bounds (drawable->id, &sx1, &sy1, &sx2, &sy2);
+  gimp_drawable_mask_bounds (drawable->drawable_id, &sx1, &sy1, &sx2, &sy2);
   width = sx2 - sx1;
   height = sy2 - sy1;
   tile_source_init_from_drawable (&source, drawable, sx1, sy1, width, height);
@@ -618,7 +617,7 @@
                   matrix, 2 * my_config.mat_width + 1,
                   &update_progress_closure);
   gimp_drawable_flush (drawable);
-  gimp_drawable_merge_shadow (drawable->id, TRUE);
-  gimp_drawable_update (drawable->id, sx1, sy1, width, height);
+  gimp_drawable_merge_shadow (drawable->drawable_id, TRUE);
+  gimp_drawable_update (drawable->drawable_id, sx1, sy1, width, height);
   g_free (matrix);
 }
