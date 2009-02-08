--- ./slload.c.orig	1999-08-22 12:43:32.000000000 -0400
+++ ./slload.c	2009-01-18 22:12:58.000000000 -0500
@@ -84,7 +84,7 @@
 	SLang_free_slstring(name);
 	SLdeallocate_load_type(x);
 
-	if (SLang_Error) return -1;
+	if (SLang_get_error()) return -1;
 
 	return 0;
 }
