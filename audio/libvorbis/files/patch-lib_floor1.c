
$FreeBSD$

--- lib/floor1.c.orig	Mon Aug 13 13:33:39 2001
+++ lib/floor1.c	Fri Aug 17 01:09:12 2001
@@ -226,7 +226,7 @@
 
   /* also store a sorted position index */
   for(i=0;i<n;i++)sortpointer[i]=info->postlist+i;
-  qsort(sortpointer,n,sizeof(int),icomp);
+  qsort(sortpointer,n,sizeof(int *),icomp);
 
   /* points from sort order back to range number */
   for(i=0;i<n;i++)look->forward_index[i]=sortpointer[i]-info->postlist;
