--- sope-gdl1/GDLAccess/EODatabaseFault.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EODatabaseFault.m
@@ -35,6 +35,7 @@
 #import "EODatabaseFaultResolver.h"
 #import "EOArrayProxy.h"
 #import "common.h"
+#import "NGExtensions/NSException+misc.h"
 
 #if NeXT_RUNTIME || APPLE_RUNTIME
 #  include <objc/objc-class.h>
@@ -78,15 +79,15 @@ typedef struct {
 		       @"to fault",
 		       NSStringFromClass([fault class]),
 #if defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__) || (__GNU_LIBOBJC__ >= 20100911)
-		       class_getInstanceSize([self class])];
+		       (int)class_getInstanceSize([self class])];
 #else
 			   ((Class)self)->instance_size];
 #endif
     }
     fault->faultResolver = [[EOObjectFault alloc] initWithPrimaryKey:key
         entity:entity databaseChannel:channel zone:zone 
-        targetClass:fault->isa];
-    fault->isa = self;
+        targetClass:object_getClass(fault)];
+    object_setClass(fault, self);
     
     return (EODatabaseFault *)AUTORELEASE(fault);
 }
@@ -130,7 +131,7 @@ typedef struct {
 {
   EODatabaseFault *fault;
     
-  fault = [NSMutableArray allocWithZone:zone];
+  fault = (EODatabaseFault*)[NSMutableArray allocWithZone:zone];
 
 #if defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__) || (__GNU_LIBOBJC__ >= 20100911)
   if (class_getInstanceSize([fault class]) < class_getInstanceSize([self class])) {
@@ -140,19 +141,19 @@ typedef struct {
         (void)[fault autorelease];
 	[NSException raise:NSInvalidArgumentException
 		     format:
-                    @"Instances from class %s must be at least %d "
+                    @"Instances from class %@ must be at least %d "
                     @"in size to fault",
                     NSStringFromClass([fault class]),
 #if defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__) || (__GNU_LIBOBJC__ >= 20100911)
-                    class_getInstanceSize([self class])];
+                    (int)class_getInstanceSize([self class])];
 #else
 					((Class)self)->instance_size];
 #endif
   }
   fault->faultResolver = [[EOArrayFault alloc] initWithQualifier:qualifier
         fetchOrder:fetchOrder databaseChannel:channel zone:zone 
-        targetClass:fault->isa];
-  fault->isa = self;
+        targetClass:object_getClass(fault)];
+  object_setClass(fault, self);
 
   return (NSArray *)AUTORELEASE(fault);
 }
@@ -161,7 +162,7 @@ typedef struct {
   EODatabaseFault *aFault = (EODatabaseFault *)fault;
 
   // Check that argument is fault
-  if (aFault->isa != self)
+  if (object_getClass(aFault) != self)
     return nil;
     
   return [(EODatabaseFaultResolver *)aFault->faultResolver primaryKey];
@@ -171,7 +172,7 @@ typedef struct {
   EODatabaseFault *aFault = (EODatabaseFault *)fault;
 
   // Check that argument is fault
-  if (aFault->isa != self)
+  if (object_getClass(aFault) != self)
     return nil;
 
   return [(EODatabaseFaultResolver *)aFault->faultResolver entity];
@@ -181,7 +182,7 @@ typedef struct {
   EODatabaseFault *aFault = (EODatabaseFault *)fault;
 
   // Check that argument is fault
-  if (aFault->isa != self)
+  if (object_getClass(aFault) != self)
     return nil;
     
   return [(EODatabaseFaultResolver *)aFault->faultResolver qualifier];
@@ -191,7 +192,7 @@ typedef struct {
   EODatabaseFault *aFault = (EODatabaseFault *)fault;
 
   // Check that argument is fault
-  if (aFault->isa != self)
+  if (object_getClass(aFault) != self)
     return nil;
     
   return [(EODatabaseFaultResolver *)aFault->faultResolver fetchOrder];
@@ -201,7 +202,7 @@ typedef struct {
   EODatabaseFault *aFault = (EODatabaseFault *)fault;
 
   // Check that argument is fault
-  if (aFault->isa != self)
+  if (object_getClass(aFault) != self)
     return nil;
     
   return [(EODatabaseFaultResolver *)aFault->faultResolver databaseChannel];
