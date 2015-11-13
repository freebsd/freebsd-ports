--- src/common_init.c.orig	2015-02-03 23:59:14 UTC
+++ src/common_init.c
@@ -72,7 +72,9 @@ pci_system_init( void )
 void
 pci_system_init_dev_mem(int fd)
 {
-#ifdef __OpenBSD__
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    pci_system_freebsd_init_dev_mem(fd);
+#elif defined(__OpenBSD__)
     pci_system_openbsd_init_dev_mem(fd);
 #endif
 }
