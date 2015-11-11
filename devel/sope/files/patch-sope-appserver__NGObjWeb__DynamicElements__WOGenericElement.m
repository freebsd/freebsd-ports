--- sope-appserver/NGObjWeb/DynamicElements/WOGenericElement.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/DynamicElements/WOGenericElement.m
@@ -77,10 +77,9 @@ typedef struct {
   [children autorelease];
   
   /* construct self ... */
-  self = [(WODynamicElement *)self initWithName:name 
+  return (WOGenericElement*)[(WODynamicElement *)self initWithName:name 
                                    associations:assocs 
                                    contentElements:children];
-  return self;
 }
 
 - (BOOL)_isASCIIString:(NSString *)_s {
