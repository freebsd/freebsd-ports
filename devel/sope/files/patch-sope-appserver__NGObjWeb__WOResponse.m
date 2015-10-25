--- sope-appserver/NGObjWeb/WOResponse.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOResponse.m
@@ -305,7 +305,7 @@ static __inline__ char *monthName(int m)
     if ([data length] == 0)
       [ms appendString:@" empty-content"];
     else
-      [ms appendFormat:@" content-size=%i", [data length]];
+      [ms appendFormat:@" content-size=%i", (int)[data length]];
   }
   else
     [ms appendString:@" no-content"];
