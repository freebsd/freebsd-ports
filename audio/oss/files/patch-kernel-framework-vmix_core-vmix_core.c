--- kernel/framework/vmix_core/vmix_core.c	Wed Oct 20 04:11:22 2010 +0300
+++ kernel/framework/vmix_core/vmix_core.c	Fri Feb 17 00:25:21 2012 +0200
@@ -1691,8 +1691,11 @@
 						&vmix_driver,
 						sizeof (audiodrv_t),
 						opts,
-						AFMT_S16_NE | AFMT_S32_NE |
-						AFMT_FLOAT, mixer, -1)) < 0)
+#ifdef CONFIG_OSS_VMIX_FLOAT
+						AFMT_FLOAT |
+#endif
+						AFMT_S16_NE | AFMT_S32_NE,
+						mixer, -1)) < 0)
     {
       return portc->audio_dev;
     }
