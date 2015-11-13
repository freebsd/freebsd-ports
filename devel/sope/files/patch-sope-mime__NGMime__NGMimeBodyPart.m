--- sope-mime/NGMime/NGMimeBodyPart.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/NGMimeBodyPart.m
@@ -206,10 +206,10 @@
   else if ([b isKindOfClass:[NSString class]] ||
            [b isKindOfClass:[NSData class]]) {
     if ([b length] < 512) {
-      [d appendFormat:@" bodyLen=%i body=%@", [b length], b];
+      [d appendFormat:@" bodyLen=%i body=%@", (int)[b length], b];
     }
     else
-      [d appendFormat:@" body[len=%i]", [b length]];
+      [d appendFormat:@" body[len=%i]", (int)[b length]];
   }
   else
     [d appendFormat:@" body=%@", b];
