--- sope-core/EOControl/EOKeyComparisonQualifier.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOKeyComparisonQualifier.m
@@ -200,7 +200,7 @@ static EONull *null = nil;
     return NO;
   if (![self->rightKey isEqual:[(EOKeyComparisonQualifier *)_qual rightKey]])
     return NO;
-  if (sel_eq(self->operator, [(EOKeyComparisonQualifier *)_qual selector]))
+  if (sel_isEqual(self->operator, [(EOKeyComparisonQualifier *)_qual selector]))
     return YES;
   return NO;
 }
