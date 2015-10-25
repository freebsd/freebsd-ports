--- sope-gdl1/GDLAccess/EOAttribute.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOAttribute.m
@@ -84,7 +84,7 @@ static EONull   *null = nil;
 }
 
 // Is equal only if same name; used to make aliasing ordering stable
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [self->name hash];
 }
 
@@ -535,7 +535,7 @@ static inline void _addToPropList(NSMuta
     return @"";
 
   clen = [self cStringLength];
-#if GNU_RUNTIME
+#if GNU_RUNTIME && !defined(__GNUSTEP_RUNTIME__)
   s = objc_atomic_malloc(clen + 4);
 #else
   s = malloc(clen + 4);
