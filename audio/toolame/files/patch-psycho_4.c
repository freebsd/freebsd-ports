--- psycho_4.c.orig	Thu Mar 27 16:58:41 2003
+++ psycho_4.c	Thu Mar 27 16:59:20 2003
@@ -330,6 +330,8 @@
 void psycho_4_init (double sfreq, options *glopts)
 {
   int i, j;
+  int partition_count; /* keep a count of the partitions */
+  int cbase; /* current base index for the bark range calculation */
 
   /* Allocate memory for all the static variables */
   psycho_4_allocmem();
@@ -365,8 +367,8 @@
      Starting from line 0, all lines within 0.33 of the starting
      bark are added to the same partition. When a line is greater
      by 0.33 of a bark, start a new partition.  */
-  int partition_count = 0; /* keep a count of the partitions */
-  int cbase = 0; /* current base index for the bark range calculation */
+  partition_count = 0;
+  cbase = 0;
   for (i=0;i<HBLKSIZE;i++) {
     if ((bark[i] - bark[cbase]) > 0.33) { /* 1/3 critical band? */
       /* this frequency line is too different from the starting line,
