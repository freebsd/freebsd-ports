--- ngsolve/linalg/order.hpp.orig
+++ ngsolve/linalg/order.hpp
@@ -118,7 +118,7 @@
   ///
   void * operator new(size_t);
   ///
-  void operator delete (void *, size_t);
+  void operator delete (void *);
 };
   
 
