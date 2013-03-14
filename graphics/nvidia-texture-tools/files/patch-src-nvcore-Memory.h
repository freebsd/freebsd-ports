--- src/nvcore/Memory.h.orig	2010-05-14 21:59:28.000000000 +0400
+++ src/nvcore/Memory.h	2013-03-13 11:44:40.704932899 +0400
@@ -28,7 +28,7 @@
 
 // Override new/delete
 
-inline void * operator new (size_t size) throw()
+inline void * operator new (size_t size) throw(std::bad_alloc)
 {
 	return nv::mem::malloc(size); 
 }
@@ -38,7 +38,7 @@
 	nv::mem::free(p); 
 }
 
-inline void * operator new [] (size_t size) throw()
+inline void * operator new [] (size_t size) throw(std::bad_alloc)
 {
 	return nv::mem::malloc(size);
 }
