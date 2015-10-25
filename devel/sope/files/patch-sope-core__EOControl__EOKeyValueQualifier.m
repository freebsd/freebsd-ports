--- sope-core/EOControl/EOKeyValueQualifier.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOKeyValueQualifier.m
@@ -227,7 +227,7 @@ static EONull *null = nil;
     return NO;
   if (![self->value isEqual:[(EOKeyValueQualifier *)_qual value]])
     return NO;
-  if (sel_eq(self->operator, [(EOKeyValueQualifier *)_qual selector]))
+  if (sel_isEqual(self->operator, [(EOKeyValueQualifier *)_qual selector]))
     return YES;
   return NO;
 }
