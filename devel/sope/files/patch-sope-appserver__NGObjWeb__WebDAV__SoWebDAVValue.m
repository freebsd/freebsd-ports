--- sope-appserver/NGObjWeb/WebDAV/SoWebDAVValue.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WebDAV/SoWebDAVValue.m
@@ -78,7 +78,7 @@
 	
 	if ((p = [encNS objectForKey:ns]) == nil) {
 	  if ((p = [_prefixes objectForKey:ns]) == nil) {
-	    p = [NSString stringWithFormat:@"a%i", [encNS count]];
+	    p = [NSString stringWithFormat:@"a%i", (int)[encNS count]];
 	    [encNS setObject:p forKey:ns];
 	    [ms appendString:@" xmlns:"];
 	    [ms appendString:p];
