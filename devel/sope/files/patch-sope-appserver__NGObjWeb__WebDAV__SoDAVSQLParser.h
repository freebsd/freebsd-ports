--- sope-appserver/NGObjWeb/WebDAV/SoDAVSQLParser.h.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WebDAV/SoDAVSQLParser.h
@@ -64,7 +64,7 @@
   consume:(BOOL)consume;
 - (BOOL)parseQualifier:(EOQualifier **)result
   from:(unichar **)pos length:(unsigned *)len;
-- (BOOL)parseScope:(NSString **)_scope:(NSString **)_entity
+- (BOOL)parseScope:(NSString **)_scope :(NSString **)_entity
   from:(unichar **)pos length:(unsigned *)len;
 
 - (BOOL)parseColumnName:(NSString **)result
