--- sources/3rd-party/nvtt/nvcore/Memory.h.orig	2018-09-02 12:42:44 UTC
+++ sources/3rd-party/nvtt/nvcore/Memory.h
@@ -28,7 +28,7 @@ namespace nv
 
 // Override new/delete
 
-inline void * operator new (size_t size) throw()
+inline void * operator new (size_t size) _THROW_BAD_ALLOC
 {
 	return nv::mem::malloc(size); 
 }
@@ -38,7 +38,7 @@ inline void operator delete (void *p) throw()
 	nv::mem::free(p); 
 }
 
-inline void * operator new [] (size_t size) throw()
+inline void * operator new [] (size_t size) _THROW_BAD_ALLOC
 {
 	return nv::mem::malloc(size);
 }
