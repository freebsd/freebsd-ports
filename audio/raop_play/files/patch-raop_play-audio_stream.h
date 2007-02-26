--- raop_play/audio_stream.h.orig	Thu Jul 28 04:43:17 2005
+++ raop_play/audio_stream.h	Fri Aug 12 09:46:45 2005
@@ -20,6 +20,13 @@
 #ifndef __AUDIO_STREAM_H_
 #define __AUDIO_STREAM_H_
 
+#define __u8 u_int8_t
+#define __u16 u_int16_t
+#define __u32 u_int32_t
+#define __s8 int8_t
+#define __s16 int16_t
+#define __s32 int32_t
+
 #include <signal.h>
 
 typedef enum data_type_t {
