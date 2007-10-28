--- nero/src/ADefs.h.orig	2007-10-28 11:33:28.000000000 +0900
+++ nero/src/ADefs.h	2007-10-28 11:33:43.000000000 +0900
@@ -138,7 +138,7 @@
 
       // Allocators.
       private: static void *operator new    (size_t size);
-      private: static void  operator delete (void *zone);
+      public:  static void  operator delete (void *zone);
       public:  static void *operator new    (size_t size, CNodeASSet &NS);
 
       // Modifiers.
