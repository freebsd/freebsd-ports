--- idlc/source/parser.yy.orig	Wed Jul 10 11:43:18 2002
+++ idlc/source/parser.yy	Thu Oct 31 10:00:47 2002
@@ -995,7 +995,8 @@
 	{
 		idlc()->setParseState(PS_ConstantDeclSeen);
 	}
-	';'
+	';' {};
+
 
 const_dcl : 
 	IDL_CONST
@@ -1316,7 +1317,7 @@
 		 * Push the scope of the exception on the scopes stack
 		 */
 		idlc()->scopes()->push(pExcept);
-		delete $1
+		delete $1;
 	}
 	'{'
 	{
@@ -1705,10 +1706,10 @@
 	{
 		idlc()->setParseState(PS_TypedefSeen);
 	}
-	type_declarator
-	| struct_type
-	| union_type
-	| enum_type
+	type_declarator {}
+	| struct_type {}
+	| union_type {}
+	| enum_type {}
 	;
 
 type_declarator :
