--- sope-appserver/NGObjWeb/WebDAV/SoWebDAVRenderer.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WebDAV/SoWebDAVRenderer.m
@@ -1311,7 +1311,7 @@ static BOOL         useRelativeURLs = YE
     [r appendContentString:@"204 No Content"];
   else {
     NSString *s;
-    s = [NSString stringWithFormat:@"%i code%i"];
+    s = [NSString stringWithFormat:@"%i code", _code];
     [r appendContentString:s];
   }
   [r appendContentString:@"</D:status>"];
