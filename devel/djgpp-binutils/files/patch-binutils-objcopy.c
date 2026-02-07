--- binutils/objcopy.c	2007/06/29 00:34:14	1.115
+++ binutils/objcopy.c	2007/07/02 08:05:06	1.116
@@ -910,8 +910,7 @@
 {
   asymbol **from = isyms, **to = osyms;
   long src_count = 0, dst_count = 0;
-  int relocatable = (abfd->flags & (HAS_RELOC | EXEC_P | DYNAMIC))
-		    == HAS_RELOC;
+  int relocatable = (abfd->flags & (EXEC_P | DYNAMIC)) == 0;
 
   for (; src_count < symcount; src_count++)
     {
