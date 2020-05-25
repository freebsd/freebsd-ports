--- connectivity/source/parse/sqlbison.y.orig	2019-09-17 22:55:11 UTC
+++ connectivity/source/parse/sqlbison.y
@@ -1,3 +1,4 @@
+%define parse.error verbose
 %{
 /**************************************************************
  * 
@@ -123,8 +124,6 @@ static connectivity::OSQLInternalNode* newNode(const :
 
 
 connectivity::OSQLParser* xxx_pGLOBAL_SQLPARSER;
-
-#define YYERROR_VERBOSE
 
 #define SQLyyerror(s)						\
 {											\
