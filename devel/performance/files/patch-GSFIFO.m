--- GSFIFO.m.orig	2011-10-25 13:51:10.000000000 +0200
+++ GSFIFO.m	2011-11-04 10:22:18.000000000 +0100
@@ -421,7 +421,7 @@
   _items = (void*)NSAllocateCollectable(c * sizeof(void*), NSScannedOption);
   if (YES == mp || YES == mc)
     {
-      condition = [NSCondition new];
+      condition = [NSConditionLock new];
     }
   name = [n copy];
   if (nil == a)
