--- sope-mime/NGMime/NGMimeJoinedData.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/NGMimeJoinedData.m
@@ -168,7 +168,7 @@
   ms = [NSMutableString stringWithCapacity:128];
   [ms appendFormat:@"<0x%p[%@]:", self, NSStringFromClass([self class])];
   [ms appendFormat:@" joinedDataObjects=%d>",
-        [self->joinedDataObjects count]];
+        (int)[self->joinedDataObjects count]];
   [ms appendString:@">"];
   return ms;
 }
