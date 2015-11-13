--- sope-mime/NGMime/NGMimePartGenerator.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/NGMimePartGenerator.m
@@ -92,7 +92,7 @@ static BOOL       debugOn = NO;
     self->result = nil;
   }
   self->result = (self->useMimeData)
-    ? [[NGMimeJoinedData alloc] init]
+    ? (NSMutableData*)[[NGMimeJoinedData alloc] init]
     : [[NSMutableData alloc] initWithCapacity:4096];
   
   if ([self->result respondsToSelector:@selector(methodForSelector:)]) {
