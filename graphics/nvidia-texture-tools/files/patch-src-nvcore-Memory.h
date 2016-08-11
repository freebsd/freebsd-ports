--- src/nvcore/Memory.h.orig	2010-05-15 09:12:05 UTC
+++ src/nvcore/Memory.h
@@ -28,7 +28,7 @@ namespace nv
 
 // Override new/delete
 
-inline void * operator new (size_t size) throw()
+inline void * operator new (size_t size) throw(std::bad_alloc)
 {
 	return nv::mem::malloc(size); 
 }
@@ -38,7 +38,7 @@ inline void operator delete (void *p) th
 	nv::mem::free(p); 
 }
 
-inline void * operator new [] (size_t size) throw()
+inline void * operator new [] (size_t size) throw(std::bad_alloc)
 {
 	return nv::mem::malloc(size);
 }
