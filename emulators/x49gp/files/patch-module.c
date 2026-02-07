--- module.c.orig	2014-01-09 17:55:30.000000000 +0000
+++ module.c	2014-01-09 17:55:54.000000000 +0000
@@ -257,7 +257,7 @@
 		return NULL;
 	}
 
-	path = g_build_filename(home, basename, filename, NULL);
+	path = g_build_filename(/*home,*/ basename, filename, NULL);
 	if (NULL == path) {
 		fprintf(stderr, "%s: %s:%u: Out of memory\n",
 			module->name, __FUNCTION__, __LINE__);
