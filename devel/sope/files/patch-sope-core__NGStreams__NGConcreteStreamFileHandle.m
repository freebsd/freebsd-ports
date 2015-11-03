--- sope-core/NGStreams/NGConcreteStreamFileHandle.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGConcreteStreamFileHandle.m
@@ -118,7 +118,7 @@
 
   *(&data) = [NSMutableData dataWithCapacity:2048];
   *(&bs) = [self->stream isKindOfClass:[NGBufferedStream class]]
-    ? [self->stream retain]
+    ? (id)[self->stream retain]
     : [(NGBufferedStream *)[NGBufferedStream alloc] 
           initWithSource:self->stream];
 
