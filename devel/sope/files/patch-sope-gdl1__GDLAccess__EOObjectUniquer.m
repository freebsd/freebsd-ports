--- sope-gdl1/GDLAccess/EOObjectUniquer.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOObjectUniquer.m
@@ -49,7 +49,7 @@ static BOOL uniquerCompare(NSMapTable *t
 
 static NSString* uniqDescription(NSMapTable *t, EOUniquerRecord* rec) {
   return [NSString stringWithFormat:
-                     @"<<pkey:%08x entity:%08x object:%08x snapshot:%08x>>",
+                     @"<<pkey:%p entity:%p object:%p snapshot:%p>>",
                      rec->pkey, rec->entity, rec->object, rec->snapshot];
 }
 
