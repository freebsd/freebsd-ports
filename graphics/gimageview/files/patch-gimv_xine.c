--- plugins/image_view/gimv_xine.c.orig
+++ plugins/image_view/gimv_xine.c
@@ -381,7 +381,11 @@ frame_output_cb (void *gxine_gen,
 }
 
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 static xine_vo_driver_t *
+#else
+static xine_video_port_t *
+#endif
 load_video_out_driver (GimvXine *this)
 {
 #if defined(GDK_WINDOWING_X11)
@@ -393,7 +397,11 @@ load_video_out_driver (GimvXine *this)
 
    GimvXinePrivate *priv;
    const char *video_driver_id;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
    xine_vo_driver_t *vo_driver;
+#else
+   xine_video_port_t *vo_driver;
+#endif
 
    g_return_val_if_fail (GIMV_IS_XINE (this), NULL);
    priv = this->private;
@@ -449,11 +457,19 @@ load_video_out_driver (GimvXine *this)
 }
 
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 static xine_ao_driver_t *
+#else
+static xine_audio_port_t *
+#endif
 load_audio_out_driver (GimvXine *this)
 {
    GimvXinePrivate *priv;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
    xine_ao_driver_t *ao_driver;
+#else
+   xine_audio_port_t *ao_driver;
+#endif
    const char *audio_driver_id;
 
    g_return_val_if_fail (GIMV_IS_XINE (this), NULL);
