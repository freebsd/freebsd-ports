--- main/SAPI.c.orig	Sun Jan  1 14:46:59 2006
+++ main/SAPI.c	Fri May  5 08:02:13 2006
@@ -582,7 +582,7 @@
 					ptr++;
 					len--;
 				}
-#if HAVE_ZLIB
+#if 1
 				if(!strncmp(ptr, "image/", sizeof("image/")-1)) {
 					zend_alter_ini_entry("zlib.output_compression", sizeof("zlib.output_compression"), "0", sizeof("0") - 1, PHP_INI_USER, PHP_INI_STAGE_RUNTIME);
 				}
@@ -729,7 +729,7 @@
 		return SUCCESS;
 	}
 
-#if HAVE_ZLIB
+#if 1
 	/* Add output compression headers at this late stage in order to make
 	   it possible to switch it off inside the script. */
 
