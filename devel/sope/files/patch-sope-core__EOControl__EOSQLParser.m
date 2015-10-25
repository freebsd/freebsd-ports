--- sope-core/EOControl/EOSQLParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOSQLParser.m
@@ -404,7 +404,7 @@ static inline BOOL isTokStopChar(unichar
   return YES;
 }
 
-- (BOOL)parseScope:(NSString **)_scope:(NSString **)_entity
+- (BOOL)parseScope:(NSString **)_scope :(NSString **)_entity
   from:(unichar **)pos length:(unsigned *)len
 {
   /* 
