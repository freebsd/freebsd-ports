--- sope-appserver/NGObjWeb/Templates/WOxElemBuilder.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/Templates/WOxElemBuilder.m
@@ -191,7 +191,7 @@ static WOAssociation *yesAssoc = nil;
       }
     }
     else {
-      NSLog(@"%s: couldn't allocate builder (class=%@)", cn);
+      NSLog(@"couldn't allocate builder (class=%@)", cn);
       continue;
     }
   }
