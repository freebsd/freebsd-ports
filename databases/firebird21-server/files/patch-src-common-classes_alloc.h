--- src/common/classes/alloc.h	2010-12-18 19:21:49.000000000 -0500
+++ src/common/classes/alloc.h	2010-12-18 19:23:30.000000000 -0500
@@ -47,6 +47,7 @@
 #include <stdlib.h> /* XPG: prototypes for malloc/free have to be in
 					   stdlib.h (EKU) */
 #endif
+#include <new>
 
 #ifdef _MSC_VER
 #define THROW_BAD_ALLOC
@@ -448,15 +449,6 @@
 	);
 }
 
-inline void* operator new(size_t, void* ptr) throw() 
-{
-	return ptr;
-}
-inline void* operator new[](size_t, void* ptr) throw() 
-{
-	return ptr;
-}
-
 inline void operator delete(void* mem) throw()
 {
 	Firebird::MemoryPool::globalFree(mem);
