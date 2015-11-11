--- sope-appserver/NGObjWeb/WOHTTPConnection.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOHTTPConnection.m
@@ -352,7 +352,7 @@ static BOOL logStream = NO;
   /* set content-length header */
   
   if ([content length] > 0) {
-    [_request setHeader:[NSString stringWithFormat:@"%d", [content length]]
+    [_request setHeader:[NSString stringWithFormat:@"%d", (int)[content length]]
               forKey:@"content-length"];
   }
 
