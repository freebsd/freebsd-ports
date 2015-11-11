--- sope-gdl1/PostgreSQL/PostgreSQL72DataTypeMappingException.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/PostgreSQL/PostgreSQL72DataTypeMappingException.m
@@ -46,7 +46,7 @@
   typeName = _dt;
 
   if (typeName == nil)
-    typeName = [NSString stringWithFormat:@"Oid[%i]", _dt];
+    typeName = [NSString stringWithFormat:@"Oid[%i]", (int)_dt];
   
   // TODO: fix for Cocoa/gstep Foundation?
   [self setName:@"DataTypeMappingNotSupported"];
