--- sope-gdl1/GDLAccess/EOEntity.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOEntity.m
@@ -106,7 +106,7 @@ static int _compareByName(id obj1, id ob
 }
 
 // Is equal only if same name; used to make aliasing ordering stable
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [name hash];
 }
 
@@ -1100,7 +1100,7 @@ static inline void _addToPropList(NSMuta
     unsigned cnt, cnt2;
 
     clen = [self cStringLength];
-#if GNU_RUNTIME
+#if GNU_RUNTIME && !defined(__GNUSTEP_RUNTIME__)
     s = objc_atomic_malloc(clen + 4);
 #else
     s = malloc(clen + 4);
