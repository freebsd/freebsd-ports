--- objc/sendmsg.c.orig	Thu Jun 15 05:45:10 1995
+++ objc/sendmsg.c	Mon Mar 20 13:29:13 2000
@@ -542,12 +542,15 @@
 #endif
 	 );
 
-  printf("arrays: %d = %ld bytes\n", narrays, (int)narrays*sizeof(struct sarray));
+  printf("arrays: %d = %lu bytes\n",
+	 narrays, (unsigned long)narrays*sizeof(struct sarray));
   total += narrays*sizeof(struct sarray);
-  printf("buckets: %d = %ld bytes\n", nbuckets, (int)nbuckets*sizeof(struct sbucket));
+  printf("buckets: %d = %lu bytes\n",
+	 nbuckets, (unsigned long)nbuckets*sizeof(struct sbucket));
   total += nbuckets*sizeof(struct sbucket);
 
-  printf("idxtables: %d = %ld bytes\n", idxsize, (int)idxsize*sizeof(void*));
+  printf("idxtables: %d = %lu bytes\n",
+	 idxsize, (unsigned long)idxsize*sizeof(void*));
   total += idxsize*sizeof(void*);
   printf("-----------------------------------\n");
   printf("total: %d bytes\n", total);
