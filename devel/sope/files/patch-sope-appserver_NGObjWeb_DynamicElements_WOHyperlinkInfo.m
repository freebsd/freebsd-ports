--- sope-appserver/NGObjWeb/DynamicElements/WOHyperlinkInfo.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/DynamicElements/WOHyperlinkInfo.m
@@ -27,7 +27,7 @@
 @implementation WOHyperlinkInfo
 
 - (id)initWithConfig:(NSMutableDictionary *)_config {
-  unsigned count;
+  unsigned count = (unsigned)[_config count];
 
   self->sidInUrl = YES;
   
