--- sope-appserver/WEExtensions/JSStringTable.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/JSStringTable.m
@@ -177,7 +177,7 @@
   }
   else {
     /* generate link to table file */
-    NSMutableDictionary *qd;
+    NSDictionary *qd;
     NSString *url;
     id product = nil;
     
