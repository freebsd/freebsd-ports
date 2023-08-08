--- lib/mmio-ports.c.orig	2023-03-04 15:27:09 UTC
+++ lib/mmio-ports.c
@@ -298,7 +298,11 @@ conf1_init(struct pci_access *a)
   if (!validate_addrs(addrs))
     a->error("Option %s has invalid address format \"%s\".", addrs_param_name, addrs);
 
+#if defined(O_DSYNC)
   a->fd = open(devmem, O_RDWR | O_DSYNC); /* O_DSYNC bypass CPU cache for mmap() on Linux */
+#else
+  a->fd = open(devmem, O_RDWR); /* O_DSYNC bypass CPU cache for mmap() on Linux */
+#endif
   if (a->fd < 0)
     a->error("Cannot open %s: %s.", devmem, strerror(errno));
 }
