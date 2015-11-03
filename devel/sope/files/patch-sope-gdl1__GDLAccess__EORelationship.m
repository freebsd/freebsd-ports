--- sope-gdl1/GDLAccess/EORelationship.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EORelationship.m
@@ -84,7 +84,7 @@ static EONull *null = nil;
 }
 
 // Is equal only if same name; used to make aliasing ordering stable
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [self->name hash];
 }
 
@@ -405,7 +405,7 @@ static EONull *null = nil;
     NS_DURING
       [self setDefinition:self->definition];
     NS_HANDLER {
-      NSLog([localException reason]);
+      NSLog(@"%@", [localException reason]);
       [[self->entity model] errorInReading];
     }
     NS_ENDHANDLER;
