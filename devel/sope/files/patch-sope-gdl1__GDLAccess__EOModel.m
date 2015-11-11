--- sope-gdl1/GDLAccess/EOModel.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOModel.m
@@ -255,7 +255,7 @@ void EOModel_linkCategories(void) {
   NSMutableDictionary *model = [NSMutableDictionary dictionaryWithCapacity:64];
   int i, count;
     
-  [model setObject:[[NSNumber numberWithInt:[isa version]] stringValue]
+  [model setObject:[[NSNumber numberWithInt:[object_getClass(self) version]] stringValue]
 	 forKey:@"EOModelVersion"];
   if (name)
         [model setObject:name forKey:@"name"];
@@ -416,7 +416,7 @@ void EOModel_linkCategories(void) {
   if ((s = [self adaptorName]))      [ms appendFormat:@" adaptor=%@", s];
   if ((s = [self adaptorClassName])) [ms appendFormat:@" adaptor-class=%@", s];
   
-  [ms appendFormat:@" #entities=%d", [self->entities count]];
+  [ms appendFormat:@" #entities=%d", (int)[self->entities count]];
   
   [ms appendString:@">"];
   return ms;
