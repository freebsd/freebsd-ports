--- rplayd/sound.h.orig	Wed Jun  9 15:27:44 1999
+++ rplayd/sound.h	Wed Jun 21 22:29:37 2000
@@ -170,9 +170,9 @@
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
 
