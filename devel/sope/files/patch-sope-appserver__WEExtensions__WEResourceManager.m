--- sope-appserver/WEExtensions/WEResourceManager.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WEResourceManager.m
@@ -620,7 +620,7 @@ checkCache(NSDictionary *_cache, WEResou
     }
     [ms appendString:_name];
     [ms appendFormat: @"?lm=%u",
-        (NSUInteger) [lastModified timeIntervalSince1970]];
+        (unsigned) [lastModified timeIntervalSince1970]];
       
     url = ms;
     if (debugOn) [self debugWithFormat:@"FOUND: '%@'", url];
