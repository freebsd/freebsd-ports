--- sope-appserver/NGObjWeb/WOHttpAdaptor/WOHttpTransaction.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOHttpAdaptor/WOHttpTransaction.m
@@ -1021,9 +1021,9 @@ static __inline__ const char *monthAbbr(
   [buf appendString:@"\" "];
   [buf appendFormat:@"%i %i",  
          [_response status],
-         [[_response content] length]];
+         (int)[[_response content] length]];
   if (doExtLog)
-    [buf appendFormat:@"/%i", [[_request content] length]];
+    [buf appendFormat:@"/%i", (int)[[_request content] length]];
   
   /* append duration */
   if (lstartDate != nil)
