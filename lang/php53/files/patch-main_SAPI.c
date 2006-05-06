--- main/SAPI.c.orig	Sun Jan  1 13:50:17 2006
+++ main/SAPI.c	Wed May  3 09:38:09 2006
@@ -602,7 +602,7 @@
 					ptr++;
 					len--;
 				}
-#if HAVE_ZLIB
+#if 1
 				if(!strncmp(ptr, "image/", sizeof("image/")-1)) {
 					zend_alter_ini_entry("zlib.output_compression", sizeof("zlib.output_compression"), "0", sizeof("0") - 1, PHP_INI_USER, PHP_INI_STAGE_RUNTIME);
 				}
@@ -756,7 +756,7 @@
 		return SUCCESS;
 	}
 
-#if HAVE_ZLIB
+#if 1
 	/* Add output compression headers at this late stage in order to make
 	   it possible to switch it off inside the script. */
 
