--- src/pciaccess_private.h.orig	2008-10-11 18:31:00.000000000 +0000
+++ src/pciaccess_private.h	2009-03-29 20:07:50.000000000 +0000
@@ -136,6 +136,7 @@
 
 extern int pci_system_linux_sysfs_create( void );
 extern int pci_system_freebsd_create( void );
+extern void pci_system_freebsd_init_dev_mem( int );
 extern int pci_system_netbsd_create( void );
 extern int pci_system_openbsd_create( void );
 extern void pci_system_openbsd_init_dev_mem( int );
