--- plugins/mpeg4ip/faad2.cpp.orig	Wed Sep 29 03:20:19 2004
+++ plugins/mpeg4ip/faad2.cpp	Wed Sep 29 03:31:53 2004
@@ -237,7 +237,7 @@
       aac->m_vft->audio_configure(aac->m_ifptr,
                   aac->m_freq,
                   aac->m_chans,
-                  AUDIO_S16SYS,
+                  (audio_format_t)AUDIO_S16SYS,
                   aac->m_output_frame_size);
       uint8_t *now = aac->m_vft->audio_get_buffer(aac->m_ifptr);
       aac->m_audio_inited = 1;
