--- sope-core/EOControl/EOKeyGlobalID.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOKeyGlobalID.m
@@ -96,7 +96,7 @@
   if (_other == nil)  return NO;
   if (_other == self) return YES;
   otherKey = _other;
-  if (otherKey->isa   != self->isa)   return NO;
+  if (object_getClass(otherKey)   != object_getClass(self))   return NO;
   if (otherKey->count != self->count) return NO;
   if (![otherKey->entityName isEqualToString:self->entityName]) return NO;
   
