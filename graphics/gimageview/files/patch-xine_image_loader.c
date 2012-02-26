--- plugins/image_view/xine_image_loader.c.orig
+++ plugins/image_view/xine_image_loader.c
@@ -57,8 +57,13 @@ gimv_xine_image_loader_load_file (GimvIm
    GimvXinePrivImage *pimage = NULL;
    xine_t *xine;
    xine_stream_t *stream;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
    xine_vo_driver_t *vo_driver;
    xine_ao_driver_t *ao_driver;
+#else
+   xine_video_port_t *vo_driver;
+   xine_audio_port_t *ao_driver;
+#endif
    guchar *rgb = NULL;
    gint width, height;
    gint ret = 0;
