--- src/pciaccess_private.h.orig	2015-02-03 23:59:14 UTC
+++ src/pciaccess_private.h
@@ -185,6 +185,7 @@ extern struct pci_system * pci_sys;
 
 extern int pci_system_linux_sysfs_create( void );
 extern int pci_system_freebsd_create( void );
+extern void pci_system_freebsd_init_dev_mem( int );
 extern int pci_system_netbsd_create( void );
 extern int pci_system_openbsd_create( void );
 extern void pci_system_openbsd_init_dev_mem( int );
