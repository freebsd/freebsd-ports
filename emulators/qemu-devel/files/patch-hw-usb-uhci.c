# 1.6
Index: qemu/hw/usb-uhci.c
@@ -153,6 +153,7 @@
     switch(addr) {
     case 0x0c:
         val = s->sof_timing;
+        break;
     default:
         val = 0xff;
         break;
@@ -654,6 +655,7 @@
     pci_conf[0x0b] = 0x0c;
     pci_conf[0x0e] = 0x00; // header_type
     pci_conf[0x3d] = 4; // interrupt pin 3
+    pci_conf[0x60] = 0x10; // release number
     
     for(i = 0; i < NB_PORTS; i++) {
         port = &s->ports[i];
@@ -666,6 +668,8 @@
 
     uhci_reset(s);
 
-    pci_register_io_region(&s->dev, 0, 0x20, 
+    /* Use region 4 for consistency with real hardware.  BSD guests seem
+       to rely on this.  */
+    pci_register_io_region(&s->dev, 4, 0x20, 
                            PCI_ADDRESS_SPACE_IO, uhci_map);
 }
