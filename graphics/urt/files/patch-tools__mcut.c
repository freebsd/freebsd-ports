--- tools/mcut.c.orig	1992-01-24 01:24:41.000000000 +0900
+++ tools/mcut.c	2012-10-15 22:52:09.000000000 +0900
@@ -232,7 +232,7 @@
  * has a slot for a color map index, so the back pointer it followed
  * only once.
  */
-void
+int
 main ( argc, argv )
 int argc;
 char ** argv;
@@ -791,7 +791,7 @@
 		    TRACE( tmp_cb, cb_list )
 		    {
 			register color_t *newcol = &tmp_cb->color;
-			register newdist = DISTANCE( ref_col, *newcol );
+			register int newdist = DISTANCE( ref_col, *newcol );
 
 			if ( newdist < dist )
 			{
@@ -963,7 +963,7 @@
 cmp_radices ( h1, h2 )
 histogram_t **h1, **h2;
 {
-    register c1 = -1, c2 = -1;
+    register int c1 = -1, c2 = -1;
 
     if ( *h1 )
 	c1 = (*h1)->color & mask;
