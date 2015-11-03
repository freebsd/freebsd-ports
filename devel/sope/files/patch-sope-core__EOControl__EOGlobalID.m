--- sope-core/EOControl/EOGlobalID.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOGlobalID.m
@@ -95,7 +95,7 @@ static unsigned int   ip;
 }
 
 - (id)init {
-  [self->isa assignGloballyUniqueBytes:&(self->idbuffer[0])];
+  [object_getClass(self) assignGloballyUniqueBytes:&(self->idbuffer[0])];
   return self;
 }
 
