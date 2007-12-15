--- tools/into.c.orig	Thu Apr 30 09:10:15 1992
+++ tools/into.c	Thu Nov 29 16:17:55 2007
@@ -41,9 +41,12 @@
 short forceflg;				/* overwrite an unwritable file? */
 
 extern int errno;
+
+#ifndef BSD
 extern char *sys_errlist[];
+#endif
 
-void
+int
 main(argc, argv)
 int argc;
 char **argv;
@@ -82,7 +85,7 @@
     }
     else
 	strcpy( buf, temp );
-    mktemp( buf );
+    mkstemp( buf );
 
     if ( (outf = fopen( buf, "w" )) == NULL )
     {
