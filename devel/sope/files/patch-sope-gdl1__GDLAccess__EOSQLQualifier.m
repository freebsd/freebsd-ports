--- sope-gdl1/GDLAccess/EOSQLQualifier.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOSQLQualifier.m
@@ -39,6 +39,7 @@
 #include <EOControl/EOKeyValueCoding.h>
 #include <EOControl/EONull.h>
 #import "EOQualifierScanner.h"
+#import "NGExtensions/NSException+misc.h"
 
 #if LIB_FOUNDATION_LIBRARY
 #  include <extensions/DefaultScannerHandler.h>
@@ -468,7 +469,7 @@ handle_attribute(EOSQLQualifier *self, i
 - (id)copyWithZone:(NSZone*)zone {
   EOSQLQualifier* copy = nil;
 
-  copy                    = [[self->isa allocWithZone:zone] init];
+  copy                    = [[object_getClass(self) allocWithZone:zone] init];
   copy->entity            = RETAIN(self->entity);
   copy->content           = [self->content           mutableCopyWithZone:zone];
   copy->relationshipPaths = [self->relationshipPaths mutableCopyWithZone:zone];
