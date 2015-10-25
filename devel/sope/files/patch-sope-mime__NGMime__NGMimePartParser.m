--- sope-mime/NGMime/NGMimePartParser.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/NGMimePartParser.m
@@ -1025,7 +1025,7 @@ static NSString *fieldNameForCString(id 
               NSMakeRange(self->dataIdx, self->byteLen - self->dataIdx)];
   if ([data length] != _len) {
     NSLog(@"%s[%i]: got wrong data %d _len %d", __PRETTY_FUNCTION__, __LINE__,
-          [data length], _len);
+          (int)[data length], _len);
     return nil;
   }
   return data;
