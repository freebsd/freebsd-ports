--- plug-ins/xslt/xslt.c.orig	Mon Mar 17 15:10:23 2003
+++ plug-ins/xslt/xslt.c	Mon Mar 17 15:10:59 2003
@@ -291,7 +291,7 @@
 	path = g_module_build_path("\Windows", "xslt");
 #else
 	/* FIXME: We should have a --with-xslt-prefix and use this */
-	path = g_module_build_path("/usr/lib", "xslt");
+	path = g_module_build_path("/usr/local/lib", "xslt");
 #endif	
 	xslt_module = g_module_open(path, 0);
 	if(xslt_module == NULL) {
