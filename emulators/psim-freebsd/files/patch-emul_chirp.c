diff -r -u sim/ppc/emul_chirp.c /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/emul_chirp.c
--- sim/ppc/emul_chirp.c	Thu Apr 15 18:35:09 1999
+++ /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/emul_chirp.c	Sun Oct  7 16:16:57 2001
@@ -1884,6 +1884,11 @@
 	       (unsigned long)chirp->sizeof_code);
     tree_parse(node, "./wimg %d", 0x7);
     tree_parse(node, "./pp %d", 0x2);
+    node = tree_parse(root, "/cpus/cpu@0");
+    tree_parse(node, "./translations 0x%lx 0x%lx 0x%0lx 0x%0lx 0x%0lx",
+	(unsigned long)chirp->code_va, (unsigned long)chirp->sizeof_code,
+	(unsigned long)chirp->code_ra, 0); 
+    node = tree_parse(root, "/chosen/mmu */cpus/cpu@0");
   }
 
   /* map in the program to run */
