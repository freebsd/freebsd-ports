--- sim/ppc/emul_chirp.c.orig	Sun Jun 22 23:03:40 2003
+++ sim/ppc/emul_chirp.c	Wed Jan 26 12:06:16 2005
@@ -1880,6 +1880,11 @@
 	       (unsigned long)chirp->sizeof_stack);
     tree_parse(node, "./wimg %d", 0x7);
     tree_parse(node, "./pp %d", 0x2);
+    node = tree_parse(root, "/cpus/cpu@0");
+    tree_parse(node, "./translations 0x%lx 0x%lx 0x%0lx 0x%0lx 0x%0lx",
+       (unsigned long)chirp->code_va, (unsigned long)chirp->sizeof_code,
+       (unsigned long)chirp->code_ra, 0); 
+    node = tree_parse(root, "/chosen/mmu */cpus/cpu@0");
   }
 
   /* map in the chrp openboot callback code */
