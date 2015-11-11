--- sope-appserver/NGObjWeb/DynamicElements/WOHyperlink.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/DynamicElements/WOHyperlink.m
@@ -75,7 +75,7 @@
     temporaryHyperlink = [_WOTemporaryHyperlink allocWithZone:zone];
   
   if (self == WOHyperlinkClass)
-    return temporaryHyperlink;
+    return (id)temporaryHyperlink;
   else {
 #if PROFILE_CLUSTERS
     static unsigned totalCount        = 0;
