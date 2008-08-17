--- parheaders.h	2005/11/27 03:48:37	1.1
+++ parheaders.h	2006/04/18 08:49:39	1.2
@@ -9,7 +9,7 @@
   int other_files;
   int block_size;
   int data_blocks;
-  int data_size;
+  long int data_size;
   int chunk_size;
   
   ParHeaders(void);
