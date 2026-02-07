--- sope-mime/NGMime/NGMimeType.m.orig	2023-06-20 10:08:44 UTC
+++ sope-mime/NGMime/NGMimeType.m
@@ -125,13 +125,13 @@ static Class NSStringClass  = Nil;
     encoding = NSKoreanEUCStringEncoding;
   }
   else if ([charset isEqualToString:@"big5"]) {
-    encoding = NSBIG5StringEncoding;
+    encoding = NSBig5StringEncoding;
   }
   else if ([charset isEqualToString:@"iso-2022-jp"]) {
     encoding = NSISO2022JPStringEncoding;
   }
   else if ([charset isEqualToString:@"gb2312"]) {
-    encoding = NSGB2312StringEncoding;
+    encoding = NSChineseEUCStringEncoding;
   }
   else if ([charset isEqualToString:@"koi8-r"]) {
     encoding = NSKOI8RStringEncoding;
