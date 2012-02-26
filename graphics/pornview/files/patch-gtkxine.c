--- src/support/widgets/gtkxine.c.orig
+++ src/support/widgets/gtkxine.c
@@ -244,13 +244,21 @@ frame_output_cb (void *gxine_gen,
     *dest_pixel_aspect = video_pixel_aspect * gxine->display_ratio;
 }
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 static xine_vo_driver_t *
+#else
+static xine_video_port_t *
+#endif
 load_video_out_driver (GtkXine * this)
 {
     double  res_h, res_v;
     x11_visual_t vis;
     const char *video_driver_id;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
     xine_vo_driver_t *vo_driver;
+#else
+    xine_video_port_t *vo_driver;
+#endif
 
     vis.display = this->display;
     vis.screen = this->screen;
@@ -296,10 +304,18 @@ load_video_out_driver (GtkXine * this)
 				   XINE_VISUAL_TYPE_X11, (void *) &vis);
 }
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 static xine_ao_driver_t *
+#else
+static xine_audio_port_t *
+#endif
 load_audio_out_driver (GtkXine * this)
 {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
     xine_ao_driver_t *ao_driver;
+#else
+    xine_audio_port_t *ao_driver;
+#endif
     const char *audio_driver_id;
 
     /*
@@ -354,8 +370,13 @@ xine_thread (void *this_gen)
 	      if (event.xexpose.count != 0)
 		  break;
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	      xine_gui_send_vo_data (this->stream,
-				     XINE_GUI_SEND_EXPOSE_EVENT, &event);
+	       		     XINE_GUI_SEND_EXPOSE_EVENT, &event);
+#else
+	      xine_port_send_gui_data (this->vo_driver,
+	       		     XINE_GUI_SEND_EXPOSE_EVENT, &event);
+#endif
 	      break;
 
 	  case FocusIn:	/* happens only in fullscreen mode */
@@ -368,8 +389,13 @@ xine_thread (void *this_gen)
 
 	if (event.type == this->completion_event)
 	{
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	    xine_gui_send_vo_data (this->stream,
 				   XINE_GUI_SEND_COMPLETION_EVENT, &event);
+#else
+	    xine_port_send_gui_data (this->vo_driver,
+	       		             XINE_GUI_SEND_EXPOSE_EVENT, &event);
+#endif
 	    /*
 	     * printf ("gtkxine: completion event\n"); 
 	     */
@@ -632,7 +658,7 @@ gtk_xine_unrealize (GtkWidget * widget)
      */
     if (this->vo_driver != NULL)
 	xine_close_video_driver (this->xine, this->vo_driver);
-    if (this->vo_driver != NULL)
+    if (this->ao_driver != NULL)
 	xine_close_audio_driver (this->xine, this->ao_driver);
 
     /*
@@ -748,6 +774,7 @@ gtk_xine_play (GtkXine * gtx, gint pos, 
     return retval;
 }
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 gint
 gtk_xine_trick_mode (GtkXine * gtx, gint mode, gint value)
 {
@@ -757,6 +784,7 @@ gtk_xine_trick_mode (GtkXine * gtx, gint
 
     return xine_trick_mode (gtx->stream, mode, value);
 }
+#endif
 
 gint
 gtk_xine_get_pos_length (GtkXine * gtx, gint * pos_stream,
@@ -1001,9 +1029,15 @@ gtk_xine_set_fullscreen (GtkXine * gtx, 
 			gtx->toplevel, RevertToNone, CurrentTime);
 	XMoveWindow (gtx->display, gtx->fullscreen_window, 0, 0);
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	xine_gui_send_vo_data (gtx->stream,
 			       XINE_GUI_SEND_DRAWABLE_CHANGED,
 			       (void *) gtx->fullscreen_window);
+#else
+	xine_port_send_gui_data (gtx->vo_driver,
+	       		         XINE_GUI_SEND_DRAWABLE_CHANGED,
+			         (void *) gtx->fullscreen_window);
+#endif
 
 	/*
 	 * switch off mouse cursor
@@ -1014,9 +1048,15 @@ gtk_xine_set_fullscreen (GtkXine * gtx, 
     }
     else
     {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	xine_gui_send_vo_data (gtx->stream,
 			       XINE_GUI_SEND_DRAWABLE_CHANGED,
 			       (void *) gtx->video_window);
+#else
+	xine_port_send_gui_data (gtx->vo_driver,
+	       		         XINE_GUI_SEND_DRAWABLE_CHANGED,
+			         (void *) gtx->video_window);
+#endif
 
 	XDestroyWindow (gtx->display, gtx->fullscreen_window);
     }
