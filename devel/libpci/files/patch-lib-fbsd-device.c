--- lib/fbsd-device.c.orig	2017-11-17 12:57:00 UTC
+++ lib/fbsd-device.c
@@ -254,7 +254,7 @@ fbsd_read(struct pci_dev *d, int pos, by
 
   if (d->access->fd_rw < 0)
     {
-      d->access->warn("fbsd_read: missing permissions");
+      d->access->warning("fbsd_read: missing permissions");
       return 0;
     }
 
@@ -303,7 +303,7 @@ fbsd_write(struct pci_dev *d, int pos, b
 
   if (d->access->fd_rw < 0)
     {
-      d->access->warn("fbsd_write: missing permissions");
+      d->access->warning("fbsd_write: missing permissions");
       return 0;
     }
 
