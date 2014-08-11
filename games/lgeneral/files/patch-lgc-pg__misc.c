--- ./lgc-pg/misc.c.orig	2011-08-08 04:03:56.000000000 -0400
+++ ./lgc-pg/misc.c	2014-08-10 23:06:31.000000000 -0400
@@ -405,7 +405,10 @@
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
