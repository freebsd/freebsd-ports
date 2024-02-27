--- nvidia-drm-freebsd-lkpi.c.orig	2024-02-22 01:03:15 UTC
+++ nvidia-drm-freebsd-lkpi.c
@@ -148,7 +148,6 @@ MODULE_DEPEND(nvidia_drm, linuxkpi, 1, 1, 1);
 LKPI_DRIVER_MODULE(nvidia_drm, nv_drm_init, nv_drm_exit);
 LKPI_PNP_INFO(pci, nvidia_drm, nv_module_device_table);
 MODULE_DEPEND(nvidia_drm, linuxkpi, 1, 1, 1);
-MODULE_DEPEND(nvidia_drm, linuxkpi_gplv2, 1, 1, 1);
 MODULE_DEPEND(nvidia_drm, drmn, 2, 2, 2);
 MODULE_DEPEND(nvidia_drm, dmabuf, 1, 1, 1);
 MODULE_DEPEND(nvidia_drm, nvidia, 1, 1, 1);
