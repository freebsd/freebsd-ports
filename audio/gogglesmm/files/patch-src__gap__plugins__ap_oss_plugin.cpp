--- src/gap/plugins/ap_oss_plugin.cpp.orig
+++ src/gap/plugins/ap_oss_plugin.cpp
@@ -117,7 +117,7 @@
 #ifdef SNDCTL_DSP_COOKEDMODE
     /// Turn off automatic resampling.
     FXint enabled=(config.flags&OSSConfig::DeviceNoResample) ? 0 : 1;
-    if (ioctl(fd,SNDCTL_DSP_COOKEDMODE,&enabled)==-1)
+    if (ioctl(handle,SNDCTL_DSP_COOKEDMODE,&enabled)==-1)
       GM_DEBUG_PRINT("[oss] unable to set cooked mode\n");
 #endif
 
