--- kernel/framework/audio/audio_core.c.orig	2008-07-14 22:48:00.000000000 -0400
+++ kernel/framework/audio/audio_core.c	2008-07-15 12:18:55.000000000 -0400
@@ -3584,6 +3584,9 @@
 	}
       return 0;
 
+#ifdef __FreeBSD__
+    case __SIOR('P', 4, int):
+#endif
     case SNDCTL_DSP_GETBLKSIZE:
       return *arg = getblksize (adev);
 
