--- ./src/Mixfix/top.yy.orig	2014-09-03 03:00:02.000000000 +0200
+++ ./src/Mixfix/top.yy	2014-09-03 03:02:15.000000000 +0200
@@ -59,7 +59,6 @@
 #define store(token)		tokenSequence.append(token)
 #define fragClear()		fragments.contractTo(0);
 #define fragStore(token)	fragments.append(token)
-#define YYPARSE_PARAM	parseResult
 #define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))
 
 #define CM		interpreter.getCurrentModule()
@@ -91,12 +90,13 @@
 Int64 number;
 Int64 number2;
 
-static void yyerror(char *s);
+static void yyerror(UserLevelRewritingContext::ParseResult *parseResult, char *s);
 
 void cleanUpModuleExpression();
 void cleanUpParser();
 void missingSpace(const Token& token);
 %}
+%parse-param { UserLevelRewritingContext::ParseResult *parseResult }
 %pure_parser
 
 %union
