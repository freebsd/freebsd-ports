--- sope-gdl1/PostgreSQL/NSString+PostgreSQL72.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/PostgreSQL/NSString+PostgreSQL72.m
@@ -145,13 +145,15 @@ static NSCharacterSet *spaceSet = nil;
   range.length = 0;
 
   for (range.location = ([self length] - 1);
-         range.location >= 0;
-         range.location++, range.length++) {
+         ;
+         range.location--, range.length++) {
       unichar c;
       
       c = charAtIndex(self, @selector(characterAtIndex:), range.location);
       if (![spaceSet characterIsMember:c])
         break;
+      if (range.location == 0)
+        break;
   }
     
   if (range.length > 0) {
