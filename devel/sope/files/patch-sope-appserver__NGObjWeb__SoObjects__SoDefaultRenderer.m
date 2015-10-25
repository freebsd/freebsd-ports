--- sope-appserver/NGObjWeb/SoObjects/SoDefaultRenderer.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/SoObjects/SoDefaultRenderer.m
@@ -154,7 +154,7 @@ static int debugOn = 0;
   
   [r setStatus:200];
   [r setHeader:@"application/octet-stream" forKey:@"content-type"];
-  [r setHeader:[NSString stringWithFormat:@"%i", [_data length]] 
+  [r setHeader:[NSString stringWithFormat:@"%i", (int)[_data length]] 
      forKey:@"content-length"];
   [r setContent:_data];
   return nil;
