--- sope-appserver/NGObjWeb/NGHttp/NGUrlFormCoder.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/NGHttp/NGUrlFormCoder.m
@@ -93,7 +93,7 @@ static __inline__ NSString *urlStringFro
                             encoding:NSUTF8StringEncoding];
   if (debugDecoding) {
     NSLog(@"decoded data len %d value (len=%d): %@", 
-	  len, [value length], value);
+	  len, (int)[value length], value);
   }
   return value;
 #if 0
@@ -177,7 +177,7 @@ NGHashMap *NGDecodeUrlFormParameters(con
 - (NSString *)stringByApplyingURLEncoding {
   /* NGExtensions/NSString+misc.h */
   NSLog(@"Note: Called deprecated -stringByApplyingURLEncoding method "
-	@"(use -stringByEscapingURL instead)", __PRETTY_FUNCTION__);
+	@"(use -stringByEscapingURL instead)");
   return [self stringByEscapingURL];
 }
 
