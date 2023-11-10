--- nvidia-drm-freebsd-lkpi.c.orig	2023-11-06 18:11:13 UTC
+++ nvidia-drm-freebsd-lkpi.c
@@ -228,7 +228,6 @@ MODULE_DEPEND(nvidia_drm, linuxkpi, 1, 1, 1);
 
 LKPI_DRIVER_MODULE(nvidia_drm, nv_drm_init, nv_drm_exit);
 MODULE_DEPEND(nvidia_drm, linuxkpi, 1, 1, 1);
-MODULE_DEPEND(nvidia_drm, linuxkpi_gplv2, 1, 1, 1);
 MODULE_DEPEND(nvidia_drm, drmn, 2, 2, 2);
 MODULE_DEPEND(nvidia_drm, dmabuf, 1, 1, 1);
 MODULE_DEPEND(nvidia_drm, nvidia, 1, 1, 1);
