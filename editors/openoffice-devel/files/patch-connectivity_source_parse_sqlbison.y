--- connectivity/source/parse/sqlbison.y.orig	2019-09-17 22:55:11 UTC
+++ connectivity/source/parse/sqlbison.y
@@ -1,3 +1,4 @@
+%define parse.error verbose
 %{
 /**************************************************************
  * 
@@ -123,9 +124,6 @@ static connectivity::OSQLInternalNode* newNode(const :
 
 
 connectivity::OSQLParser* xxx_pGLOBAL_SQLPARSER;
-
-#define YYDEBUG 1
-#define YYERROR_VERBOSE
 
 #define SQLyyerror(s)						\
 {											\
