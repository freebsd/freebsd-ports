--- ext/pcre/php_pcre.c.orig	Sun Feb  1 20:56:16 2004
+++ ext/pcre/php_pcre.c	Sat May  8 00:50:32 2004
@@ -47,20 +47,6 @@
 
 ZEND_DECLARE_MODULE_GLOBALS(pcre)
 
-
-static void *php_pcre_malloc(size_t size)
-{
-	return pemalloc(size, 1);
-}
-
-
-static void php_pcre_free(void *ptr)
-{
-	if (ptr)
-	pefree(ptr, 1);
-}
-
-
 static void php_free_pcre_cache(void *data)
 {
 	pcre_cache_entry *pce = (pcre_cache_entry *) data;
@@ -107,14 +93,6 @@
 	REGISTER_LONG_CONSTANT("PREG_SPLIT_OFFSET_CAPTURE", PREG_SPLIT_OFFSET_CAPTURE, CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("PREG_GREP_INVERT", PREG_GREP_INVERT, CONST_CS | CONST_PERSISTENT);
 
-	pcre_malloc = php_pcre_malloc;
-	pcre_free = php_pcre_free;
-
-#ifdef NO_RECURSE
-	pcre_stack_malloc = php_pcre_malloc;
-	pcre_stack_free = php_pcre_free;
-#endif
-	
 	return SUCCESS;
 }
 /* }}} */
@@ -548,7 +526,7 @@
 					}
 				}
 
-				php_pcre_free((void *) stringlist);
+				pcre_free((void *) stringlist);
 			}
 		}
 		else { /* Failed to match */
