--- sope-appserver/NGObjWeb/Templates/WOTemplate.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/Templates/WOTemplate.m
@@ -133,7 +133,7 @@
       [ms appendFormat:@" url=%@", [self->url absoluteString]];
   }
   if (self->subcomponentInfos)
-    [ms appendFormat:@" #subcomponents=%i", [self->subcomponentInfos count]];
+    [ms appendFormat:@" #subcomponents=%i", (int)[self->subcomponentInfos count]];
   
   [ms appendString:@">"];
   return ms;
