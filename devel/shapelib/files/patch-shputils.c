--- shputils.c.orig	Mon Apr  7 21:03:22 2003
+++ shputils.c	Tue Dec 12 21:28:33 2006
@@ -274,7 +274,7 @@
                 if (factor == 0)
                 {
                   if (infactor ==0)
-                  { puts("ERROR: Input unit must be defined before output unit"); exit(); }
+                  { puts("ERROR: Input unit must be defined before output unit"); exit( 1 ); }
                   factor=infactor/outfactor;
                 }
                 printf("Output file coordinate values will be factored by %lg\n",factor);
@@ -319,7 +319,7 @@
     {
     	ti = DBFGetFieldCount( hDBF );
 	showitems();
-	exit(0);
+	exit( 0 );
     }
      
     if (iclip) check_theme_bnd();
