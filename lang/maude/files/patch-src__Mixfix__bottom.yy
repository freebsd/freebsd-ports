--- ./src/Mixfix/bottom.yy.orig	2014-09-03 02:49:14.000000000 +0200
+++ ./src/Mixfix/bottom.yy	2014-09-03 02:50:56.000000000 +0200
@@ -23,7 +23,7 @@
 %%
 
 static void
-yyerror(char *s)
+yyerror(UserLevelRewritingContext::ParseResult *parseResult, char *s)
 {
   if (!(UserLevelRewritingContext::interrupted()))
     IssueWarning(LineNumber(lineNumber) << ": " << s);
