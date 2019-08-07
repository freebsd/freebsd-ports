--- src/freebsd_pci.c.orig	2019-07-17 16:25:27 UTC
+++ src/freebsd_pci.c
@@ -421,24 +421,6 @@ pci_system_freebsd_destroy( void )
     freebsd_pci_sys = NULL;
 }
 
-static int
-pci_device_freebsd_has_kernel_driver( struct pci_device *dev )
-{
-    struct pci_io io;
-
-    io.pi_sel.pc_domain = dev->domain;
-    io.pi_sel.pc_bus = dev->bus;
-    io.pi_sel.pc_dev = dev->dev;
-    io.pi_sel.pc_func = dev->func;
-    
-    if ( ioctl( freebsd_pci_sys->pcidev, PCIOCATTACHED, &io ) < 0 ) {
-	return 0;
-    }
-
-    /* if io.pi_data is 0, no driver is attached */
-    return io.pi_data == 0 ? 0 : 1;
-}
-
 static struct pci_io_handle *
 pci_device_freebsd_open_legacy_io( struct pci_io_handle *ret,
 				   struct pci_device *dev, pciaddr_t base,
@@ -614,7 +596,7 @@ static const struct pci_system_methods freebsd_pci_met
     .fill_capabilities = pci_fill_capabilities_generic,
     .enable = NULL,
     .boot_vga = NULL,
-    .has_kernel_driver = pci_device_freebsd_has_kernel_driver,
+    .has_kernel_driver = NULL,
 
     .open_device_io = pci_device_freebsd_open_io,
     .open_legacy_io = pci_device_freebsd_open_legacy_io,
