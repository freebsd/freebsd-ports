--- write_tables.c.orig	Mon Aug  2 08:24:03 2004
+++ write_tables.c	Wed Aug 11 09:15:44 2004
@@ -87,6 +87,7 @@
 save_binary_tables(File *file) {
   int i;
   BinaryTablesHead tables;
+  unsigned int len;
   
   tables.n_relocs = file->relocations.n;
   tables.n_strings = file->str_relocations.n;
@@ -94,13 +95,13 @@
   tables.tables_size = file->tables.cur - file->tables.start;
   tables.strings_size = file->strings.cur - file->strings.start;
 
-  unsigned int len = sizeof(BinaryTablesHead) +
+  len = sizeof(BinaryTablesHead) +
     tables.tables_size + tables.strings_size +
     (file->relocations.n * sizeof(void*)) +
     (file->str_relocations.n * sizeof(void*));
 
   if (file->str) {
-    file->cur_str = *file->str = (unsigned char*)malloc(len);
+    file->cur_str = *file->str = (unsigned char*)MALLOC(len);
     *file->str_len = len;
   }
 
