--- sope-appserver/NGObjWeb/WOStatisticsStore.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOStatisticsStore.m
@@ -35,7 +35,7 @@
   unsigned       zippedResponsesCount;
   unsigned       totalZippedSize;
   unsigned       largestResponseSize;
-  unsigned       smallestResponseSize;
+  NSInteger      smallestResponseSize;
   NSTimeInterval minimumDuration;
   NSTimeInterval maximumDuration;
   NSTimeInterval totalDuration;
@@ -420,7 +420,7 @@ static id mkdbl(double d) {
   /* response */
   
   [result appendFormat:@"%i %i",
-            [_response status], [[_response content] length]];
+            [_response status], (int)[[_response content] length]];
   
   if ((startDate = [request startDate]) != nil) {
     NSTimeInterval duration;
