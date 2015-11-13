--- sope-gdl1/GDLAccess/EORecordDictionary.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EORecordDictionary.m
@@ -55,7 +55,7 @@ static NSDictionary *emptyDict = nil;
 - (id)init  {
   RELEASE(self);
   if (emptyDict == nil) emptyDict = [[NSDictionary alloc] init];
-  return [emptyDict retain];
+  return (id)[emptyDict retain];
 }
 
 - (id)initWithObjects:(id *)_objects forKeys:(id *)_keys 
@@ -64,12 +64,12 @@ static NSDictionary *emptyDict = nil;
   if (_count == 0) {
         RELEASE(self);
 	if (emptyDict == nil) emptyDict = [[NSDictionary alloc] init];
-	return [emptyDict retain];
+	return (id)[emptyDict retain];
   }
   
   if (_count == 1) {
         RELEASE(self);
-        return [[NSDictionary alloc]
+        return (id)[[NSDictionary alloc]
                               initWithObjects:_objects forKeys:_keys
                               count:_count];
   }
