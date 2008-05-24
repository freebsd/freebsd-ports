--- misc/mktrace/mktrace.c.orig	Tue Aug 31 03:14:17 2004
+++ misc/mktrace/mktrace.c	Wed Jul 13 16:31:28 2005
@@ -70,9 +70,9 @@
   else
   {
     printf( "enter FASTA filename: " );
-    gets( ifnm );
+    fgets( ifnm, sizeof(ifnm), stdin );
     printf( "enter output filename: " );
-    gets( ofnm );
+    fgets( ofnm, sizeof(ofnm), stdin );
   }
 
   /*
