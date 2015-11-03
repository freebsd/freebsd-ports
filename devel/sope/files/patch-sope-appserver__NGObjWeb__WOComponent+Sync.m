--- sope-appserver/NGObjWeb/WOComponent+Sync.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOComponent+Sync.m
@@ -87,7 +87,7 @@ void WOComponent_syncFromParent(WOCompon
 #if NeXT_RUNTIME
   takeValue = (void *)[self methodForSelector:@selector(takeValue:forKey:)];
 #elif GNUSTEP_BASE_LIBRARY
-  takeValue = (void*)method_get_imp(class_get_instance_method(self->isa,
+  takeValue = (void*)method_get_imp(class_get_instance_method(object_getClass(self),
                 @selector(setValue:forKey:)));
 #else  
   takeValue = (void*)method_get_imp(class_get_instance_method(self->isa,
@@ -148,7 +148,7 @@ void WOComponent_syncToParent(WOComponen
 #if NeXT_RUNTIME
   getValue = (void *)[self methodForSelector:@selector(valueForKey:)];
 #else
-  getValue = (void*)method_get_imp(class_get_instance_method(self->isa,
+  getValue = (void*)method_get_imp(class_get_instance_method(object_getClass(self),
                 @selector(valueForKey:)));
 #endif
   
