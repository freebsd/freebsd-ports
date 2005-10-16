--- unix/unix.c.orig	Sat Feb 26 16:43:42 2005
+++ unix/unix.c	Fri Sep  9 14:36:35 2005
@@ -1042,6 +1042,16 @@
     ush z_uidgid[2];
     int have_uidgid_flg;
 
+/*---------------------------------------------------------------------------
+    Change the file permissions from default ones to those stored in the
+    zipfile.
+  ---------------------------------------------------------------------------*/
+	  
+#ifndef NO_CHMOD
+    if (fchmod(fileno(G.outfile), filtattr(__G__ G.pInfo->file_attr)))
+        perror("fchmod (file attributes) error");
+#endif
+
     fclose(G.outfile);
 
 /*---------------------------------------------------------------------------
@@ -1150,16 +1160,6 @@
               " (warning) cannot set times"));
 #endif /* ?AOS_VS */
     }
-
-/*---------------------------------------------------------------------------
-    Change the file permissions from default ones to those stored in the
-    zipfile.
-  ---------------------------------------------------------------------------*/
-
-#ifndef NO_CHMOD
-    if (chmod(G.filename, filtattr(__G__ G.pInfo->file_attr)))
-        perror("chmod (file attributes) error");
-#endif
 
 } /* end function close_outfile() */
 
