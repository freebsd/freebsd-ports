--- gdb/remote.c.orig	2005-07-20 03:56:43.000000000 +0100
+++ gdb/remote.c	2007-02-08 20:06:12.000000000 +0000
@@ -1953,6 +1953,7 @@
   int lose;
   CORE_ADDR text_addr, data_addr, bss_addr;
   struct section_offsets *offs;
+  int i;
 
   putpkt ("qOffsets");
 
@@ -2014,6 +2015,13 @@
   memcpy (offs, symfile_objfile->section_offsets,
 	  SIZEOF_N_SECTION_OFFSETS (symfile_objfile->num_sections));
 
+  /* GDB is stupid, lets fix up all sections to the same address not just a few :P */
+
+  for(i = 0; i < symfile_objfile->num_sections; i++)
+  {
+	  offs->offsets[i] = text_addr;
+  }
+#if 0
   offs->offsets[SECT_OFF_TEXT (symfile_objfile)] = text_addr;
 
   /* This is a temporary kludge to force data and bss to use the same offsets
@@ -2022,6 +2030,7 @@
 
   offs->offsets[SECT_OFF_DATA (symfile_objfile)] = data_addr;
   offs->offsets[SECT_OFF_BSS (symfile_objfile)] = data_addr;
+#endif
 
   objfile_relocate (symfile_objfile, offs);
 }
