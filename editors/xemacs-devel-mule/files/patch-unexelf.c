--- src/unexelf.c.orig	Mon Jul  4 16:11:27 2005
+++ src/unexelf.c	Thu Sep 22 22:38:19 2005
@@ -565,8 +565,8 @@
  *
  */
 int
-unexec (Extbyte *new_name, Extbyte *old_name, unsigned int UNUSED (data_start),
-	unsigned int UNUSED (bss_start), unsigned int UNUSED (entry_address))
+unexec (Extbyte *new_name, Extbyte *old_name, uintptr_t UNUSED (data_start),
+	uintptr_t UNUSED (bss_start), uintptr_t UNUSED (entry_address))
 {
   int new_file, old_file, new_file_size;
 
