
$FreeBSD$

--- stream_d.c.orig	Wed May 22 11:02:08 2002
+++ stream_d.c	Wed May 22 11:02:37 2002
@@ -23,7 +23,7 @@
  *          that should be good to about 5% precision.
  */
 
-# define N	2000000
+# define N	NSIZE
 # define NTIMES	10
 # define OFFSET	0
 
