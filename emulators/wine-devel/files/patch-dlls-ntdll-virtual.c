--- dlls/ntdll/virtual.c.orig	2008-12-07 17:26:02.000000000 +0100
+++ dlls/ntdll/virtual.c	2008-12-07 17:28:46.000000000 +0100
@@ -1249,9 +1249,7 @@
         }
     }
 
-    /* try to find space in a reserved area for the virtual heap */
-    if (!wine_mmap_enum_reserved_areas( alloc_virtual_heap, &heap_base, 1 ))
-        heap_base = wine_anon_mmap( NULL, VIRTUAL_HEAP_SIZE, PROT_READ|PROT_WRITE, 0 );
+    heap_base = wine_anon_mmap( (void *)0x81000000, VIRTUAL_HEAP_SIZE, PROT_READ|PROT_WRITE, 0 );
 
     assert( heap_base != (void *)-1 );
     virtual_heap = RtlCreateHeap( HEAP_NO_SERIALIZE, heap_base, VIRTUAL_HEAP_SIZE,
