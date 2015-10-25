--- sope-appserver/NGObjWeb/WOHttpAdaptor/WORequest+Adaptor.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOHttpAdaptor/WORequest+Adaptor.m
@@ -35,7 +35,7 @@
   if (pi == nil) pi = [[NSProcessInfo processInfo] retain];
   
   tmp = [pi procStatDictionary];
-  ASSIGN(self->startDate,       _startDate);
+  ASSIGN(self->startDate,       (NSCalendarDate*)_startDate);
   ASSIGN(self->startStatistics, tmp);
 }
 
