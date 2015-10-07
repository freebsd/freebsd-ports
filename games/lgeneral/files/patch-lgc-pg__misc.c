--- lgc-pg/misc.c.orig	2015-03-15 14:09:24 UTC
+++ lgc-pg/misc.c
@@ -428,7 +428,10 @@ const char *get_gamedir(void)
     return ".";
 #else
     static char gamedir[MAXPATHLEN];
-    snprintf( gamedir, MAXPATHLEN, "%s", INSTALLDIR );
+    if (dest_path)
+    	snprintf( gamedir, MAXPATHLEN, "%s", dest_path );
+    else
+    	snprintf( gamedir, MAXPATHLEN, "%s", INSTALLDIR );
     return gamedir;
 #endif
 }
