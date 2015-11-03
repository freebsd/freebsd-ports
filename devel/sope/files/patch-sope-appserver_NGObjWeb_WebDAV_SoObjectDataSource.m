--- sope-appserver/NGObjWeb/WebDAV/SoObjectDataSource.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WebDAV/SoObjectDataSource.m
@@ -137,7 +137,7 @@ static BOOL debugOn = NO;
   pool = [[NSAutoreleasePool alloc] init];
   i=0;
   while ((childKey = [[childKeys nextObject] stringValue]) != nil) {
-    NSDictionary *rec;
+    id rec;
     NSException  *e;
     NSString     *childHref;
     id child = nil;
