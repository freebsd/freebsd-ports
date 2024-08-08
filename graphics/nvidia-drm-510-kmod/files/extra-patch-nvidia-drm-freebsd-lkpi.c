--- nvidia-drm-freebsd-lkpi.c.orig	2024-02-22 01:03:15 UTC
+++ nvidia-drm-freebsd-lkpi.c
@@ -115,6 +115,7 @@ int nv_drm_probe_devices(void)
      * by the native nvidia.ko by using our devclass.
      */
     for (int i = 0; i < NV_MAX_DEVICES; i++) {
+        struct pci_dev *pdev;
         nv_gpu_info_t gpu_info;
         struct nvidia_softc *sc = devclass_get_softc(nvidia_devclass, i);
         if (!sc) {
@@ -124,11 +125,33 @@ int nv_drm_probe_devices(void)
         nv_state_t *nv = sc->nv_state;
 
         /*
+         * Set the ivars for this device if they are not already populated. This
+         * is the bus specific data, and linuxkpi will try to use it.
+         */
+        if (!device_get_ivars(sc->dev)) {
+            device_t parent = device_get_parent(sc->dev);
+            struct pci_devinfo *dinfo = device_get_ivars(parent);
+            device_set_ivars(sc->dev, dinfo);
+        }
+
+        /*
          * Now we have the state (which gives us the device_t), but what nvidia-drm
          * wants is a pci_dev suitable for use with linuxkpi code. We can use
-         * lkpinew_pci_dev to fill in a pci_dev struct,
+         * lkpinew_pci_dev to fill in a pci_dev struct, or linux_pci_attach on more
+         * recent kernels (introduced by 253dbe7487705).
          */
-        struct pci_dev *pdev = lkpinew_pci_dev(sc->dev);
+#if __FreeBSD_version < 1300093
+        pdev = lkpinew_pci_dev(sc->dev);
+#else
+        pdev = malloc(sizeof(*pdev), M_DEVBUF, M_WAITOK|M_ZERO);
+        if (!pdev) {
+            return -ENOMEM;
+        }
+
+        if (linux_pci_attach_device(sc->dev, NULL, NULL, pdev)) {
+            return -ENOMEM;
+        }
+#endif
         nv_lkpi_pci_devs[i] = pdev;
 
         gpu_info.gpu_id = nv->gpu_id;
