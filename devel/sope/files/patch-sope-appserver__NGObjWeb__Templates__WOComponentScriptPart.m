--- sope-appserver/NGObjWeb/Templates/WOComponentScriptPart.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/Templates/WOComponentScriptPart.m
@@ -112,7 +112,7 @@
       [ms appendFormat:@":%i", self->startLine];
   }
   else if (self->startLine > 0)
-    [ms appendFormat:@" line=%@", self->startLine];
+    [ms appendFormat:@" line=%u", self->startLine];
 
   if ([self->script length] == 0)
     [ms appendString:@" no script"];
