--- library/tulip/include/tulip/IdManager.h.orig	2007-12-18 21:33:16.000000000 +0100
+++ library/tulip/include/tulip/IdManager.h	2007-12-18 21:33:32.000000000 +0100
@@ -34,7 +34,7 @@
      Free the id given in parameter. This id
      will be accessible by a the get function.
   */
-  void IdManager::free(const unsigned int);
+  void free(const unsigned int);
   /**
      Return a new id, the returned id is choosen to minimize
      the memory space of the free list, and the fragmetation
