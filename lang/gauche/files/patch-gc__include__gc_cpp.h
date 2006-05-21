--- ./gc/include/gc_cpp.h.orig	Sat Mar  4 12:55:44 2006
+++ ./gc/include/gc_cpp.h	Tue May  9 14:38:56 2006
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
