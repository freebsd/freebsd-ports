--- src/VBox/Additions/freebsd/drm/vboxvideo_drm.c.orig	2015-03-16 13:00:32.000000000 -0400
+++ src/VBox/Additions/freebsd/drm/vboxvideo_drm.c	2015-03-27 17:40:43.686690000 -0400
@@ -54,8 +54,13 @@
 #include <sys/cdefs.h>
 __FBSDID("$FreeBSD$");
 
+#ifdef VBOXVIDEO_DRM2
+#include "dev/drm2/drmP.h"
+#include "dev/drm2/drm_pciids.h"
+#else
 #include "dev/drm/drmP.h"
 #include "dev/drm/drm_pciids.h"
+#endif
 
 #define DRIVER_AUTHOR                   "Oracle Corporation"
 #define DRIVER_NAME                     "vboxvideo"
@@ -74,6 +79,54 @@
 	vboxvideo_PCI_IDS
 };
 
+#ifdef VBOXVIDEO_DRM2
+
+static struct drm_driver vboxvideo_info = {
+	.buf_priv_size			= 1, /* No dev_priv */
+
+	.num_ioctls			= 0,
+
+	.name				= DRIVER_NAME,
+	.desc				= DRIVER_DESC,
+	.date				= DRIVER_DATE,
+	.major				= DRIVER_MAJOR,
+	.minor				= DRIVER_MINOR,
+	.patchlevel			= DRIVER_PATCHLEVEL,
+};
+
+static int
+vboxvideo_probe(device_t kdev)
+{
+	return -drm_probe_helper(kdev, vboxvideo_pciidlist);
+}
+
+static int
+vboxvideo_attach(device_t kdev)
+{
+	return -drm_attach_helper(kdev, vboxvideo_pciidlist, &vboxvideo_info);
+}
+
+static device_method_t vboxvideo_methods[] = {
+	/* Device interface */
+	DEVMETHOD(device_probe,		vboxvideo_probe),
+	DEVMETHOD(device_attach,	vboxvideo_attach),
+	DEVMETHOD(device_detach,	drm_generic_detach),
+
+	DEVMETHOD_END
+};
+
+static driver_t vboxvideo_driver = {
+	"drmn",
+	vboxvideo_methods,
+	sizeof(struct drm_device)
+};
+
+extern devclass_t drm_devclass;
+DRIVER_MODULE(vboxvideo, vgapci, vboxvideo_driver, drm_devclass, 0, 0);
+MODULE_DEPEND(vboxvideo, drmn, 1, 1, 1);
+
+#else /* !VBOXVIDEO_DRM2 */
+
 static void vboxvideo_configure(struct drm_device *dev)
 {
 #if __FreeBSD_version >= 702000
@@ -161,3 +214,5 @@
 DRIVER_MODULE(vboxvideo, pci, vboxvideo_driver, drm_devclass, 0, 0);
 #endif
 MODULE_DEPEND(vboxvideo, drm, 1, 1, 1);
+
+#endif /* VBOXVIDEO_DRM2 */
