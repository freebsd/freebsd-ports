--- lib/fbsd-device.c.orig	2017-11-17 12:57:00 UTC
+++ lib/fbsd-device.c
@@ -143,7 +143,7 @@ fbsd_scan(struct pci_access *a)
 	  t = pci_alloc_dev(a);
 	  t->bus = matches[i].pc_sel.pc_bus;
 	  t->dev = matches[i].pc_sel.pc_dev;
-	  t->dev = matches[i].pc_sel.pc_dev;
+	  t->func = matches[i].pc_sel.pc_func;
 	  t->domain = matches[i].pc_sel.pc_domain;
 	  t->domain_16 = matches[i].pc_sel.pc_domain;
 	  t->vendor_id = matches[i].pc_vendor;
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
 
