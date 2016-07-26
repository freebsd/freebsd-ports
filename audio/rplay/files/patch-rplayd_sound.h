--- rplayd/sound.h.orig	1999-06-09 06:27:44 UTC
+++ rplayd/sound.h
@@ -170,9 +170,9 @@ typedef struct _sindex
     int gsm_bit_frame_bytes;	/* Number of bytes in gsm_bit_frame */
     int gsm_fixed_buffer_size;
 #endif /* HAVE_GSM */
-#ifdef HAVE_CDROM
+#if defined(HAVE_CDROM) || defined(HAVE_HELPERS)
     int pid;
-#endif /* HAVE_CDROM */
+#endif /* HAVE_CDROM || HAVE_HELPERS */
 }
 SINDEX;
 
