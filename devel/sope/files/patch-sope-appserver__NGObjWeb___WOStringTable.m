--- sope-appserver/NGObjWeb/_WOStringTable.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/_WOStringTable.m
@@ -162,7 +162,7 @@ static NSStringEncoding stringFilesEncod
   [ms appendFormat:@"<0x%p[%@]: ", self, NSStringFromClass([self class])];
   
   if (self->path)     [ms appendFormat:@" path='%@'",   self->path];
-  if (self->data)     [ms appendFormat:@" strings=#%d", [self->data count]];
+  if (self->data)     [ms appendFormat:@" strings=#%d", (int)[self->data count]];
   if (self->lastRead) [ms appendFormat:@" loaddate=%@", self->lastRead];
   
   [ms appendString:@">"];
