--- sope-appserver/NGObjWeb/Associations/WOValueAssociation.m.orig	2015-09-16 18:26:48 UTC
+++ sope-appserver/NGObjWeb/Associations/WOValueAssociation.m
@@ -161,7 +161,7 @@ static Class StrClass = Nil;
       v = [v substringToIndex:9];
       v = [v stringByApplyingCEscaping];
       [str appendString:v];
-      [str appendFormat:@"...[len=%i]", [self->value length]];
+      [str appendFormat:@"...[len=%i]", (int)[self->value length]];
     }
     else {
       v = [v stringByApplyingCEscaping];
