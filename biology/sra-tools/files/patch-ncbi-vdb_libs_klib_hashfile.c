--- ncbi-vdb/libs/klib/hashfile.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/klib/hashfile.c
@@ -35,7 +35,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#if LINUX
+#if BSD || LINUX
 #include <sys/mman.h>
 #endif
 
@@ -346,7 +346,7 @@ static void * map_calloc( KHashFile * self, size_t siz
                 KLockUnlock( self->alloc_lock );
                 return NULL;
             }
-#if LINUX
+#if BSD || LINUX
             /* Not sure this helps */
             madvise( (void *)self->alloc_base, req, MADV_RANDOM );
 #endif
