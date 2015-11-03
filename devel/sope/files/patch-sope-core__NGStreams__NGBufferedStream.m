--- sope-core/NGStreams/NGBufferedStream.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGBufferedStream.m
@@ -66,7 +66,7 @@ static Class DataStreamClass = Nil;
   }
   if (*(Class *)_source == DataStreamClass) {
     [self release];
-    return [_source retain];
+    return (id)[_source retain];
   }
 
   if ((self = [super initWithSource:_source])) {
@@ -90,7 +90,7 @@ static Class DataStreamClass = Nil;
   }
   if (*(Class *)_source == DataStreamClass) {
     [self release];
-    return [_source retain];
+    return (id)[_source retain];
   }
 
   if ((self = [super initWithInputSource:_source])) {
@@ -109,7 +109,7 @@ static Class DataStreamClass = Nil;
   }
   if (*(Class *)_src == DataStreamClass) {
     [self release];
-    return [_src retain];
+    return (id)[_src retain];
   }
 
   if ((self = [super initWithOutputSource:_src])) {
