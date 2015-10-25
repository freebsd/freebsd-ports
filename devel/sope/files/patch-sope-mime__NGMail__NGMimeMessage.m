--- sope-mime/NGMail/NGMimeMessage.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMail/NGMimeMessage.m
@@ -230,7 +230,7 @@ static NGMimeType *defaultDataType = nil
     if ([b length] < 512)
       [d appendFormat:@" body=%@", b];
     else
-      [d appendFormat:@" body[len=%i]", [b length]];
+      [d appendFormat:@" body[len=%i]", (int)[b length]];
   }
   else
     [d appendFormat:@" body=%@", b];
