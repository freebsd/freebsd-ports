$FreeBSD$

--- stream_d.c.orig	Tue Nov  6 15:02:21 2001
+++ stream_d.c	Tue Nov  6 15:03:11 2001
@@ -23,7 +23,7 @@
  *          that should be good to about 5% precision.
  */
 
-# define N	1000000
+# define N	NSIZE
 # define NTIMES	10
 # define OFFSET	0
 
