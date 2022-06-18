--- rtl/freebsd/i386/cprt0.as	2022-06-16 22:38:18.787786000 -0500
+++ rtl/freebsd/i386/cprt0.as	2022-06-16 22:39:54.403673000 -0500
@@ -35,16 +35,21 @@
 
         .file   "cprt0.as"
         .ident  "FreePascal 2.6.x/2.7.x series dynlinked to libc"
-.section        .note.ABI-tag,"a",@progbits
+.section        .note.tag,"a",@note
         .p2align 2
         .type   abitag, @object
-        .size   abitag, 24
+        .size   abitag, 48
 abitag:
         .long   8
         .long   4
         .long   1
         .string "FreeBSD"
         .long   900044
+        .long   8
+        .long   4
+        .long   1
+        .string "FreeBSD"
+        .long   0
         .section	.rodata.str1.1,"aMS",@progbits,1
 .LC0:
         .string ""
