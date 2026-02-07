--- drivers/gpu/drm/drm_os_freebsd.c.bak	2022-11-05 15:37:52.826643000 -0400
+++ drivers/gpu/drm/drm_os_freebsd.c	2022-11-05 15:38:25.740620000 -0400
@@ -202,11 +202,15 @@
 #if __FreeBSD_version >= 1301505
 #if __FreeBSD_version >= 1400058
 DRIVER_MODULE(iicbus, drmn, iicbus_driver, NULL, NULL);
+#if defined(__amd64__) || defined(__aarch64__) || defined(__i386__)
 DRIVER_MODULE(acpi_iicbus, drmn, acpi_iicbus_driver, NULL, NULL);
+#endif
 #else
 DRIVER_MODULE(iicbus, drmn, iicbus_driver, iicbus_devclass, NULL, NULL);
+#if defined(__amd64__) || defined(__aarch64__) || defined(__i386__)
 DRIVER_MODULE(acpi_iicbus, drmn, acpi_iicbus_driver, iicbus_devclass, NULL,
     NULL);
+#endif
 #endif
 MODULE_DEPEND(drmn, iicbus, IICBUS_MINVER, IICBUS_PREFVER, IICBUS_MAXVER);
 MODULE_DEPEND(drmn, iic, 1, 1, 1);
