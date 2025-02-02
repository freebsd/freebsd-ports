--- src/VBox/Additions/freebsd/drm/vboxvideo_drm.c.orig	2022-07-26 18:05:21 UTC
+++ src/VBox/Additions/freebsd/drm/vboxvideo_drm.c
@@ -154,10 +154,14 @@ static driver_t vboxvideo_driver = {
 	sizeof(struct drm_device)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(vboxvideo, vgapci, vboxvideo_driver, 0, 0);
+#else
 extern devclass_t drm_devclass;
 #if __FreeBSD_version >= 700010
 DRIVER_MODULE(vboxvideo, vgapci, vboxvideo_driver, drm_devclass, 0, 0);
 #else
 DRIVER_MODULE(vboxvideo, pci, vboxvideo_driver, drm_devclass, 0, 0);
+#endif
 #endif
 MODULE_DEPEND(vboxvideo, drm, 1, 1, 1);
