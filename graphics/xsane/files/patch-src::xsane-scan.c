--- src/xsane-scan.c.tmpfile	Wed Nov 21 18:48:01 2001
+++ src/xsane-scan.c	Wed Nov 21 18:48:08 2001
@@ -1660,7 +1660,6 @@
       umask((mode_t) preferences.image_umask); /* define image file permissions */   
     }
 
-    remove(xsane.dummy_filename); /* remove existing file */
     xsane.out = fopen(xsane.dummy_filename, "wb"); /* b = binary mode for win32 */
     umask(XSANE_DEFAULT_UMASK); /* define new file permissions */   
 

