--- include/gc_cpp.h.orig	Fri Oct 22 07:47:45 2004
+++ include/gc_cpp.h	Sun Nov 13 22:19:07 2005
@@ -180,7 +180,7 @@
     inline void* operator new[]( size_t size, void *p );
     inline void operator delete[]( void* obj );
 #   ifdef GC_PLACEMENT_DELETE
-      inline void gc::operator delete[]( void*, void* );
+      inline void operator delete[]( void*, void* );
 #   endif
 #endif /* GC_OPERATOR_NEW_ARRAY */
     };    
@@ -281,7 +281,7 @@
     else
         return GC_MALLOC_UNCOLLECTABLE( size );}
 
-inline void* gc::operator new( size_t size, void *p ) {
+inline void* gc::operator new( size_t, void *p ) {
     return p;}
 
 inline void gc::operator delete( void* obj ) {
@@ -299,7 +299,7 @@
 inline void* gc::operator new[]( size_t size, GCPlacement gcp ) {
     return gc::operator new( size, gcp );}
 
-inline void* gc::operator new[]( size_t size, void *p ) {
+inline void* gc::operator new[]( size_t, void *p ) {
     return p;}
 
 inline void gc::operator delete[]( void* obj ) {
