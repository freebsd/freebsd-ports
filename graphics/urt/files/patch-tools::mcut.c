--- tools/mcut.c.orig	Thu Mar 10 20:54:44 2005
+++ tools/mcut.c	Thu Mar 10 20:56:44 2005
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
