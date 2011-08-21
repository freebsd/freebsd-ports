Index: a/../sgabios-read-only/rom16.ld
===================================================================
--- sgabios-read-only/rom16.ld	(revision 8)
+++ sgabios-read-only/rom16.ld	(working copy)
@@ -3,8 +3,8 @@
  */
 
 /* Script for -z combreloc: combine and sort reloc sections */
-OUTPUT_FORMAT("elf32-i386", "elf32-i386",
-	      "elf32-i386")
+OUTPUT_FORMAT("elf32-i386-freebsd", "elf32-i386-freebsd",
+	      "elf32-i386-freebsd")
 OUTPUT_ARCH(i386)
 EXTERN(_start)
 ENTRY(_start)
