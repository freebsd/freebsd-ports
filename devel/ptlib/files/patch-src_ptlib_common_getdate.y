--- src/ptlib/common/getdate.y.orig	2013-02-20 02:11:52 UTC
+++ src/ptlib/common/getdate.y
@@ -106,8 +106,6 @@ struct Variables {
 
 
 #define YYPURE		1
-#define YYLEX_PARAM	VARIABLE
-#define YYPARSE_PARAM	parseParam
 
 #define yyparse		PTime_yyparse
 #define yylex		PTime_yylex
@@ -121,9 +119,9 @@ static int yyparse(void *); 
 static int yylex();
 
 #ifdef __GNUC__
-static int yyerror(char const *msg);
+static int yyerror(void *, char const *msg);
 #else
-static void yyerror(char const *msg);
+static void yyerror(void *, char const *msg);
 #endif
 
 
@@ -133,6 +131,8 @@ static void SetPossibleDate(struct Varia
 %}
 
 %pure_parser
+%parse-param {void *parseParam}
+%lex-param {void *parseParam}
 
 %union {
     time_t		Number;
@@ -1018,12 +1018,12 @@ time_t STDAPICALLTYPE PTimeParse(void * 
 #endif
 
 #ifdef __GNUC__
-int yyerror(const char * s)
+int yyerror(void *var, const char * s)
 {
   return 0;
 }
 #else
-static void yyerror(const char * s)
+static void yyerror(void *var, const char * s)
 {
 }
 #endif
