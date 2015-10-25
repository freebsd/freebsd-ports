--- sope-gdl1/GDLAccess/EODatabaseFaultResolver.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EODatabaseFaultResolver.m
@@ -191,7 +191,7 @@
 
 - (NSString *)descriptionForObject:(id)_fault {
   return [NSString stringWithFormat:
-                   @"<Array fault 0x%x (qualifier=%@, order=%@, channel=%@)>",
+                   @"<Array fault %p (qualifier=%@, order=%@, channel=%@)>",
                    _fault, qualifier, fetchOrder, channel];
 }
 
@@ -302,7 +302,7 @@
 
 - (NSString *)descriptionForObject:(id)_fault {
   return [NSString stringWithFormat:
-                     @"<Object fault 0x%X "
+                     @"<Object fault %p "
                      @"(class=%@, entity=%@, key=%@, channel=%@)>",
                      _fault,
                      NSStringFromClass(targetClass), 
