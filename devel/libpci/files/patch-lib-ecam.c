--- lib/ecam.c.orig	2023-03-05 13:45:24 UTC
+++ lib/ecam.c
@@ -924,7 +924,11 @@ ecam_init(struct pci_access *a)
   if (!validate_addrs(addrs))
     a->error("Option ecam.addrs has invalid address format \"%s\".", addrs);
 
+#if defined(O_DSYNC)
   a->fd = open(devmem, (a->writeable ? O_RDWR : O_RDONLY) | O_DSYNC);
+#else
+  a->fd = open(devmem, (a->writeable ? O_RDWR : O_RDONLY));
+#endif
   if (a->fd < 0)
     a->error("Cannot open %s: %s.", devmem, strerror(errno));
 
