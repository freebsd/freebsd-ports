--- ./include/zthread/Guard.h.orig	2005-03-12 21:10:09.000000000 -0500
+++ ./include/zthread/Guard.h	2009-04-23 15:03:09.000000000 -0400
@@ -491,7 +491,7 @@
     
   try {
     
-    if(!isDisabled())
+    if(!this->isDisabled())
       LockingPolicy::destroyScope(*this);
     
   } catch (...) { /* ignore */ }  
