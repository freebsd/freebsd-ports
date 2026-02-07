--- os_cmd/FreeBSD/ossdetect/ossdetect.c.orig	2015-01-28 08:07:32 UTC
+++ os_cmd/FreeBSD/ossdetect/ossdetect.c
@@ -376,17 +376,20 @@ pci_detect (void)
 	  char name[32];
 
 	  if (verbose > 2)
-	    printf ("%s%d@pci%d:%d:%d:\tclass=0x%06x card=0x%08x "
-		    "chip=0x%08x rev=0x%02x hdr=0x%02x\n",
-		    (p->pd_name && *p->pd_name) ? p->pd_name :
-		    "none",
-		    (p->pd_name && *p->pd_name) ? (int) p->pd_unit :
-		    p->pc_sel.pc_bus, p->pc_sel.pc_dev,
-		    p->pc_sel.pc_func, (p->pc_class << 16) |
-		    (p->pc_subclass << 8) | p->pc_progif,
-		    (p->pc_subdevice << 16) | p->pc_subvendor,
-		    (p->pc_device << 16) | p->pc_vendor,
-		    p->pc_revid, p->pc_hdr);
+            {
+	      if (p->pd_name && *p->pd_name)
+		sprintf(name, "%s%d", p->pd_name, (int) p->pd_unit);
+	      else
+		strcpy(name, "none");
+	      printf ("%s@pci%d:%d:%d:\tclass=0x%06x card=0x%08x "
+		      "chip=0x%08x rev=0x%02x hdr=0x%02x\n", name,
+		      p->pc_sel.pc_bus, p->pc_sel.pc_dev, p->pc_sel.pc_func,
+		      (p->pc_class << 16) |
+		      (p->pc_subclass << 8) | p->pc_progif,
+		      (p->pc_subdevice << 16) | p->pc_subvendor,
+		      (p->pc_device << 16) | p->pc_vendor,
+		      p->pc_revid, p->pc_hdr);
+	    }
 
 	  sprintf (name, "pcs%x,%x", p->pc_subvendor, p->pc_subdevice);
 	  if (add_drv (name, PCI_PASS))
