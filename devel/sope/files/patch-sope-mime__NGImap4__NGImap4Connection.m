--- sope-mime/NGImap4/NGImap4Connection.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Connection.m
@@ -1174,10 +1174,10 @@ NSArray *SOGoMailGetDirectChildren(NSArr
   [ms appendFormat:@" created=%@", self->creationTime];
   
   if (self->subfolders != nil)
-    [ms appendFormat:@" #cached-folders=%d", [self->subfolders count]];
+    [ms appendFormat:@" #cached-folders=%d", (int)[self->subfolders count]];
   
   if (self->cachedUIDs != nil)
-    [ms appendFormat:@" #cached-uids=%d", [self->cachedUIDs count]];
+    [ms appendFormat:@" #cached-uids=%d", (int)[self->cachedUIDs count]];
   
   [ms appendString:@">"];
   return ms;
