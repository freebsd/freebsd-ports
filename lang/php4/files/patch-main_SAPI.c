--- main/SAPI.c.orig	Fri Apr 15 10:50:01 2005
+++ main/SAPI.c	Fri Apr 15 10:50:14 2005
@@ -565,7 +565,7 @@
 					ptr++;
 					len--;
 				}
-#if HAVE_ZLIB
+#if 1
 				if(!strncmp(ptr, "image/", sizeof("image/")-1)) {
 					zend_alter_ini_entry("zlib.output_compression", sizeof("zlib.output_compression"), "0", sizeof("0") - 1, PHP_INI_USER, PHP_INI_STAGE_RUNTIME);
 				}
@@ -712,7 +712,7 @@
 		return SUCCESS;
 	}
 
-#if HAVE_ZLIB
+#if 1
 	/* Add output compression headers at this late stage in order to make
 	   it possible to switch it off inside the script. */
 
