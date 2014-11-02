--- src/ptlib/common/getdate.y.orig	2007-10-19 06:22:32 UTC
+++ src/ptlib/common/getdate.y
@@ -106,8 +106,6 @@ struct Variables {
 
 
 #define YYPURE		1
-#define YYLEX_PARAM	VARIABLE->yyInput
-#define YYPARSE_PARAM	parseParam
 
 #define yyparse		PTime_yyparse
 #define yylex		PTime_yylex
@@ -117,9 +115,9 @@ static int yyparse(void *); 
 static int yylex();
 
 #ifdef __GNUC__
-static int yyerror();
+static int yyerror(void *, char const *msg);
 #else
-static void yyerror();
+static void yyerror(void *, char const *msg);
 #endif
 
 
@@ -129,6 +127,8 @@ static void SetPossibleDate(struct Varia
 %}
 
 %pure_parser
+%parse-param {void *parseParam}
+%lex-param {void *parseParam}
 
 %union {
     time_t		Number;
@@ -718,22 +718,22 @@ static int LookupWord(char * buff, YYSTY
 #ifndef __GNUC__
 static
 #endif
-int yylex(YYSTYPE * yylval, void * yyInput)
+int yylex(YYSTYPE * yylval, struct Variables * vars)
 {
     register char	*p;
     char		buff[20];
     int			Count;
     int			sign;
-    register int	c = PTimeGetChar(yyInput);
+    register int	c = PTimeGetChar(vars->yyInput);
 
     while (c != EOF && c != '\0' && c != '\n') {
 	while (isspace(c))
-	    c = PTimeGetChar(yyInput);
+	    c = PTimeGetChar(vars->yyInput);
 
 	if (isdigit(c) || c == '-' || c == '+') {
 	    if (c == '-' || c == '+') {
 		sign = c == '-' ? -1 : 1;
-		if (!isdigit(c = PTimeGetChar(yyInput)))
+		if (!isdigit(c = PTimeGetChar(vars->yyInput)))
 		    /* skip the '-' sign */
 		    continue;
 	    }
@@ -743,10 +743,10 @@ int yylex(YYSTYPE * yylval, void * yyInp
             Count = 0; /* Count number of digits */
 	    while (isdigit(c)) {
 		yylval->Number = 10 * yylval->Number + c - '0';
-		c = PTimeGetChar(yyInput);
+		c = PTimeGetChar(vars->yyInput);
                 Count++;
 	    }
-	    PTimeUngetChar(yyInput, c);
+	    PTimeUngetChar(vars->yyInput, c);
 	    if (sign < 0)
 		yylval->Number = -yylval->Number;
 	    if (sign)
@@ -759,12 +759,12 @@ int yylex(YYSTYPE * yylval, void * yyInp
 	}
 
 	if (isalpha(c)) {
-	    for (p = buff; isalpha(c) || c == '.'; c = PTimeGetChar(yyInput)) {
+	    for (p = buff; isalpha(c) || c == '.'; c = PTimeGetChar(vars->yyInput)) {
 		if (p < &buff[sizeof(buff)-1])
 		    *p++ = (char)c;
 	    }
 	    *p = '\0';
-	    PTimeUngetChar(yyInput, c);
+	    PTimeUngetChar(vars->yyInput, c);
 	    return LookupWord(buff, yylval);
 	}
 
@@ -773,7 +773,7 @@ int yylex(YYSTYPE * yylval, void * yyInp
 
 	Count = 0;
 	do {
-	    c = PTimeGetChar(yyInput);
+	    c = PTimeGetChar(vars->yyInput);
 	    if (c == '\0' || c == EOF)
 		return c;
 	    if (c == '(')
@@ -1008,12 +1008,12 @@ time_t STDAPICALLTYPE PTimeParse(void * 
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
