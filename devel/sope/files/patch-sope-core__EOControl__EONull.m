--- sope-core/EOControl/EONull.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EONull.m
@@ -32,15 +32,15 @@
 @implementation EONull
 
 + (id)allocWithZone:(NSZone *)_zone {
-  return [NSNull allocWithZone:_zone];
+  return (EONull*)[NSNull allocWithZone:_zone];
 }
 
 + (NSNull *)null {
-  return [NSNull null];
+  return (EONull*)[NSNull null];
 }
 
 - (id)self {
-  return [NSNull null];
+  return (EONull*)[NSNull null];
 }
 
 @end
