--- src/xsane-save.c.tmpfile	Wed Nov 21 18:47:48 2001
+++ src/xsane-save.c	Wed Nov 21 18:47:56 2001
@@ -2102,7 +2102,6 @@
 
   xsane_read_pnm_header(infile, &image_info);
 
-  remove(output_filename);
   umask((mode_t) preferences.image_umask); /* define image file permissions */   
   outfile = fopen(output_filename, "wb"); /* b = binary mode for win32 */
   umask(XSANE_DEFAULT_UMASK); /* define new file permissions */   
