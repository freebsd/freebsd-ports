--- sope-mime/NGMime/NGMimeRFC822DateHeaderFieldParser.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/NGMimeRFC822DateHeaderFieldParser.m
@@ -161,7 +161,7 @@ static NSTimeZone *parseTimeZone(const c
     hours += 10 * (*(s + pos) - 48) + *(s + pos + 1) - 48;
     break;
   default:
-    NSLog (@"parseTimeZone: cannot parse time notation '%.*s'", len, s);
+    NSLog (@"parseTimeZone: cannot parse time notation '%.*s'", (int)len, s);
   }
 
   seconds += sign * (3600 * hours + 60 * minutes);
