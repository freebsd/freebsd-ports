Index: gdb/symfile.c
===================================================================
RCS file: /cvs/src/src/gdb/symfile.c,v
retrieving revision 1.143
diff -u -p -p -r1.143 symfile.c
--- symfile.c	1 Oct 2004 10:23:09 -0000	1.143
+++ symfile.c	19 Oct 2004 20:07:58 -0000
@@ -1405,7 +1405,7 @@ load_section_callback (bfd *abfd, asecti
 	  struct cleanup *old_chain;
 	  CORE_ADDR lma = bfd_section_lma (abfd, asec) + args-&gt;load_offset;
 	  bfd_size_type block_size;
-	  int err;
+	  int err = 0;
 	  const char *sect_name = bfd_get_section_name (abfd, asec);
 	  bfd_size_type sent;
 
