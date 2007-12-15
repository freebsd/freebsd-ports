--- tools/rleaddcom.c.orig	Thu Nov 29 16:12:38 2007
+++ tools/rleaddcom.c	Thu Nov 29 16:25:14 2007
@@ -60,7 +60,7 @@
  * Algorithm:
  *	[None]
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -118,7 +118,7 @@
 	}
 	else
 	    strcpy( buf, temp );
-	mktemp( buf );
+	mkstemp( buf );
 #ifndef NO_OPEN_PIPES
 	/* Compressed file special case. */
 	cp = i_fname + strlen( i_fname ) - 2;
