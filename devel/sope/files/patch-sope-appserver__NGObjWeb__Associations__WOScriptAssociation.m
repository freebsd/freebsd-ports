--- sope-appserver/NGObjWeb/Associations/WOScriptAssociation.m.orig	2015-09-16 18:26:48 UTC
+++ sope-appserver/NGObjWeb/Associations/WOScriptAssociation.m
@@ -125,7 +125,7 @@ static BOOL doDebug = NO;
       v = [v substringToIndex:9];
       v = [v stringByApplyingCEscaping];
       [str appendString:v];
-      [str appendFormat:@"...[len=%i]", [self->script length]];
+      [str appendFormat:@"...[len=%i]", (int)[self->script length]];
   }
   else {
       v = [v stringByApplyingCEscaping];
