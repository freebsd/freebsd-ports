--- include/zthread/Guard.h.orig	Wed Jul 30 00:40:13 2003
+++ include/zthread/Guard.h	Fri Dec 24 21:15:17 2004
@@ -490,7 +490,7 @@
     
   try {
     
-    if(!isDisabled())
+    if(!this->isDisabled())
       LockingPolicy::destroyScope(*this);
     
   } catch (...) { /* ignore */ }  
