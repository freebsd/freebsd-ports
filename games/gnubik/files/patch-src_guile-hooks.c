--- src/guile-hooks.c.orig	2012-01-07 17:29:10 UTC
+++ src/guile-hooks.c
@@ -202,9 +202,9 @@ read_script_directory (const char *dir_n
 
 	    scm_primitive_load (scm_from_locale_string (buffer));
 	  }
-    }
 
-  closedir (directory);
+    closedir (directory);
+  }
 }
 
 
