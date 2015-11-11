--- sope-appserver/NGObjWeb/WOMailDelivery.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOMailDelivery.m
@@ -180,7 +180,8 @@ WOMailDelivery *sharedInstance = nil;
       NSData *body;
       
       body = [(NSDictionary *)_email objectForKey:@"body"];
-      if (fwrite([body bytes], [body length], 1, toMail) < 0)
+      NSUInteger bytes = [body length];
+      if (fwrite([body bytes], bytes, 1, toMail) < bytes)
         goto failed;
     }
     fprintf(toMail, "\r\n");
