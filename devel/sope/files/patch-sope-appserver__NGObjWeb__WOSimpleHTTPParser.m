--- sope-appserver/NGObjWeb/WOSimpleHTTPParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOSimpleHTTPParser.m
@@ -449,7 +449,7 @@ static NSString *stringForHeaderName(cha
   
   while ((e = [self readNextLine]) == nil) {
     unsigned char *p, *v;
-    unsigned int  idx;
+    int  idx;
     NSString *headerName;
     NSString *headerValue;
     
