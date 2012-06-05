--- misc.c.orig	2012-06-05 13:35:29.000000000 -0500
+++ misc.c	2012-06-05 13:36:34.000000000 -0500
@@ -192,7 +192,7 @@
 
 /***  Memory allocation/freeing utils ***/
 
-void mem_alloc( void **ptr, int req )
+void mem_alloc( void **ptr, size_t req )
 {
   free_ptr( ptr );
   *ptr = malloc( req );
@@ -203,7 +203,7 @@
 
 /*------------------------------------------------------------------------*/
 
-void mem_realloc( void **ptr, int req )
+void mem_realloc( void **ptr, size_t req )
 {
   *ptr = realloc( *ptr, req );
   if( *ptr == NULL )
