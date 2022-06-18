--- rtl/freebsd/x86_64/cprt0.as	2022-06-16 22:35:12.252513000 -0500
+++ rtl/freebsd/x86_64/cprt0.as	2022-06-16 22:36:47.506865000 -0500
@@ -32,16 +32,21 @@
 #APP
         .ident  "FreePascal 2.6.x/2.7.x series dynlinked to libc"
 #NO_APP
-	.section	.note.ABI-tag,"a",@progbits
+	.section	.note.tag,"a",@note
 	.align 4
 	.type	abitag, @object
-	.size	abitag, 24
+	.size	abitag, 48
 abitag:
 	.long	8
 	.long	4
 	.long	1
 	.string	"FreeBSD"
 	.long	900044
+	.long	8
+	.long	4
+	.long	1
+	.string	"FreeBSD"
+	.long	0
 .globl __progname
 	.section	.rodata
 .LC0:
