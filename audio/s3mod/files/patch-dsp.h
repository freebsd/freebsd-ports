--- dsp.h.orig	1995-10-21 06:52:31 UTC
+++ dsp.h
@@ -34,7 +34,7 @@ extern uint8                  *audio_sta
 extern uint8                  *audio_end_buffer;
 extern uint8                  *audio_curptr;
 
-int get_dsp_device(void);
+void get_dsp_device(void);
 void write_dsp_device(void *buf, int size);
 void close_dsp_device(void);
 #endif /* DSP */
