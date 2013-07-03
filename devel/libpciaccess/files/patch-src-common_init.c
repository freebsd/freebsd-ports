--- src/common_init.c.orig	2008-10-11 18:31:00.000000000 +0000
+++ src/common_init.c	2009-03-29 20:10:52.000000000 +0000
@@ -70,7 +70,9 @@
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
