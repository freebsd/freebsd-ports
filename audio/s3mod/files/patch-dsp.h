--- dsp.h.orig	2012-10-10 23:31:11.000000000 +0800
+++ dsp.h	2012-10-10 23:31:22.000000000 +0800
@@ -34,7 +34,7 @@ extern uint8                  *audio_sta
 extern uint8                  *audio_end_buffer;
 extern uint8                  *audio_curptr;
 
-int get_dsp_device(void);
+void get_dsp_device(void);
 void write_dsp_device(void *buf, int size);
 void close_dsp_device(void);
 #endif /* DSP */
