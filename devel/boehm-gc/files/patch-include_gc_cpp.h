--- include/gc_cpp.h.orig	Thu Oct 14 12:19:56 2004
+++ include/gc_cpp.h	Thu Oct 14 12:20:15 2004
@@ -276,7 +276,7 @@
     else
         return GC_MALLOC_UNCOLLECTABLE( size );}
 
-inline void* gc::operator new( size_t size, void *p ) {
+inline void* gc::operator new( size_t, void *p ) {
     return p;}
 
 inline void gc::operator delete( void* obj ) {
@@ -294,7 +294,7 @@
 inline void* gc::operator new[]( size_t size, GCPlacement gcp ) {
     return gc::operator new( size, gcp );}
 
-inline void* gc::operator new[]( size_t size, void *p ) {
+inline void* gc::operator new[]( size_t, void *p ) {
     return p;}
 
 inline void gc::operator delete[]( void* obj ) {
