--- misc.c.orig	2004-01-24 14:18:43 UTC
+++ misc.c
@@ -113,6 +113,7 @@ int stop( int flag )
     fclose( plot_fp );
 
   exit( flag );
+  return(flag);
 }
 
 /*------------------------------------------------------------------*/
@@ -192,7 +193,7 @@ int load_line( char *buff, FILE *pfile )
 
 /***  Memory allocation/freeing utils ***/
 
-void mem_alloc( void **ptr, int req )
+void mem_alloc( void **ptr, size_t req )
 {
   free_ptr( ptr );
   *ptr = malloc( req );
@@ -203,7 +204,7 @@ void mem_alloc( void **ptr, int req )
 
 /*------------------------------------------------------------------------*/
 
-void mem_realloc( void **ptr, int req )
+void mem_realloc( void **ptr, size_t req )
 {
   *ptr = realloc( *ptr, req );
   if( *ptr == NULL )
