--- sope-core/NGStreams/NGByteBuffer.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGByteBuffer.m
@@ -44,7 +44,7 @@ static Class DataStreamClass = Nil;
   DataStreamClass   = NSClassFromString(@"NGDataStream");
 }
 
-+ (int)version {
++ (NSInteger)version {
   return [super version] + 1;
 }
 
@@ -61,7 +61,7 @@ static Class DataStreamClass = Nil;
   }
   if (*(Class *)_source == DataStreamClass) {
     [self release];
-    return [_source retain];
+    return (id)[_source retain];
   }
   if ((self = [super initWithSource:_source])) {
     unsigned size = 0;
