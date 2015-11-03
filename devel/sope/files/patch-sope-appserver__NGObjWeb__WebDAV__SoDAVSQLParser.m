--- sope-appserver/NGObjWeb/WebDAV/SoDAVSQLParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WebDAV/SoDAVSQLParser.m
@@ -396,7 +396,7 @@ static inline BOOL isTokStopChar(unichar
   return YES;
 }
 
-- (BOOL)parseScope:(NSString **)_scope:(NSString **)_entity
+- (BOOL)parseScope:(NSString **)_scope :(NSString **)_entity
   from:(unichar **)pos length:(unsigned *)len
 {
   /* 
@@ -749,7 +749,7 @@ static inline BOOL isTokStopChar(unichar
     }
     else if ([[(EOAndQualifier *)q qualifiers] count] != 3) {
       NSLog(@"  INVALID: expected 3 subqualifiers, got %i !",
-	    [[(EOAndQualifier *)q qualifiers] count]);
+	    (int)[[(EOAndQualifier *)q qualifiers] count]);
     }
 
     /* check sortordering */
@@ -767,7 +767,7 @@ static inline BOOL isTokStopChar(unichar
     }
     else if ([props count] != 14) {
       NSLog(@"  INVALID: invalid attribute count, expected 14, got %i.",
-	    [props count]);
+	    (int)[props count]);
     }
   }
   
