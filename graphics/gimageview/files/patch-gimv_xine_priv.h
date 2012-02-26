--- plugins/image_view/gimv_xine_priv.h.orig
+++ plugins/image_view/gimv_xine_priv.h
@@ -97,8 +97,13 @@ struct GimvXinePrivate_Tag
    char                    *video_driver_id;
    char                    *audio_driver_id;
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
    xine_vo_driver_t        *vo_driver;
    xine_ao_driver_t        *ao_driver;
+#else
+   xine_video_port_t       *vo_driver;
+   xine_audio_port_t       *ao_driver;
+#endif
 
    int                      xpos, ypos;
    int                      oldwidth, oldheight;
