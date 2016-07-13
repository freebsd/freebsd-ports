--- src/ldgeneric.c.orig	2014-02-05 00:21:44 UTC
+++ src/ldgeneric.c
@@ -2631,9 +2631,9 @@ ld_generic_generate_sections (struct ld_
 /* Callback function registered with on_exit to make sure the temporary
    files gets removed if something goes wrong.  */
 static void
-remove_tempfile (int status, void *arg)
+remove_tempfile (void)
 {
-  if (status != 0 && ld_state.tempfname != NULL)
+  if (ld_state.tempfname != NULL)
     unlink (ld_state.tempfname);
 }
 
@@ -2680,7 +2680,7 @@ ld_generic_open_outfile (struct ld_state
 
   /* Make sure we remove the temporary file in case something goes
      wrong.  */
-  on_exit (remove_tempfile, NULL);
+  atexit (remove_tempfile);
 
   /* Create the ELF file data for the output file.  */
   Elf *elf = ld_state.outelf = elf_begin (fd,
