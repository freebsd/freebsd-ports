Make room for terminating NUL added by sprintf()

--- source/scriptlib/Parser.c.orig	2016-12-15 02:16:03 UTC
+++ source/scriptlib/Parser.c
@@ -1828,7 +1828,7 @@ void Parser_Mult_expr2(Parser *pparser )
 
 void Parser_Unary_expr(Parser *pparser )
 {
-    static CHAR buf[MAX_TOKEN_LENGTH + 1];
+    static CHAR buf[MAX_TOKEN_LENGTH + 2];
     Instruction *pInstruction = NULL;
 
     if (ParserSet_First(&(pparser->theParserSet), postfix_expr, pparser->theNextToken.theType ))
