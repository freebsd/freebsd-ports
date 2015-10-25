--- sope-gdl1/PostgreSQL/NSData+PGVal.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/PostgreSQL/NSData+PGVal.m
@@ -84,7 +84,7 @@ static NSData *EmptyData = nil;
 
   if (doDebug) {
     NSLog(@"Note: made string (len=%i) for data (len=%i), type %@",
-	  [str length], [self length], _type);
+	  (int)[str length], (int)[self length], _type);
   }
   
   if ((len = [_type length]) == 0) {
@@ -108,7 +108,7 @@ static NSData *EmptyData = nil;
       t = [[str stringValueForPostgreSQLType:_type 
 		attribute:_attribute] copy];
       [str release];
-      if (doDebug) NSLog(@"  result len %i", [t length]);
+      if (doDebug) NSLog(@"  result len %i", (int)[t length]);
       return [t autorelease];
     }
   }
