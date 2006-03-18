# 1.19
Index: qemu/hw/ne2000.c
@@ -648,6 +648,8 @@
 {
 	NE2000State* s=(NE2000State*)opaque;
 
+        qemu_put_8s(f, &s->rxcr);
+
 	qemu_put_8s(f, &s->cmd);
 	qemu_put_be32s(f, &s->start);
 	qemu_put_be32s(f, &s->stop);
@@ -672,8 +674,13 @@
 {
 	NE2000State* s=(NE2000State*)opaque;
 
-	if (version_id != 1)
+        if (version_id == 2) {
+            qemu_get_8s(f, &s->rxcr);
+        } else if (version_id == 1) {
+            s->rxcr = 0x0c;
+        } else {
             return -EINVAL;
+        }
 
 	qemu_get_8s(f, &s->cmd);
 	qemu_get_be32s(f, &s->start);
@@ -732,7 +739,7 @@
              s->macaddr[4],
              s->macaddr[5]);
              
-    register_savevm("ne2000", 0, 1, ne2000_save, ne2000_load, s);
+    register_savevm("ne2000", 0, 2, ne2000_save, ne2000_load, s);
 }
 
 /***********************************************************/
@@ -803,7 +810,7 @@
              s->macaddr[5]);
              
     /* XXX: instance number ? */
-    register_savevm("ne2000", 0, 1, ne2000_save, ne2000_load, s);
+    register_savevm("ne2000", 0, 2, ne2000_save, ne2000_load, s);
     register_savevm("ne2000_pci", 0, 1, generic_pci_save, generic_pci_load, 
                     &d->dev);
 }
