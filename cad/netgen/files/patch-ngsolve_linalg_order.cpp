--- ngsolve/linalg/order.cpp.orig
+++ ngsolve/linalg/order.cpp
@@ -54,7 +54,7 @@
     return ball.Alloc();
   }
 
-  void CliqueEl :: operator delete (void * p, size_t)
+  void CliqueEl :: operator delete (void * p)
   {
     ball.Free (p);
   }
