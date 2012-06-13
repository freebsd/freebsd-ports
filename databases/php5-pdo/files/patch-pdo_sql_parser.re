--- pdo_sql_parser.re.orig
+++ pdo_sql_parser.re
@@ -32,12 +32,12 @@
 
 #define YYCTYPE         unsigned char
 #define YYCURSOR        cursor
-#define YYLIMIT         cursor
+#define YYLIMIT         s->end
 #define YYMARKER        s->ptr
-#define YYFILL(n)
+#define YYFILL(n)		{ RET(PDO_PARSER_EOI); }
 
 typedef struct Scanner {
-	char 	*ptr, *cur, *tok;
+	char 	*ptr, *cur, *tok, *end;
 } Scanner;
 
 static int scan(Scanner *s) 
@@ -51,7 +51,6 @@ static int scan(Scanner *s)
 	COMMENTS	= ("/*"([^*]+|[*]+[^/*])*[*]*"*/"|"--"[^\r\n]*);
 	SPECIALS	= [:?"'];
 	MULTICHAR	= [:?];
-	EOF			= [\000];
 	ANYNOEOF	= [\001-\377];
 	*/
 
@@ -64,7 +63,6 @@ static int scan(Scanner *s)
 		SPECIALS								{ SKIP_ONE(PDO_PARSER_TEXT); }
 		COMMENTS								{ RET(PDO_PARSER_TEXT); }
 		(ANYNOEOF\SPECIALS)+ 					{ RET(PDO_PARSER_TEXT); }
-		EOF										{ RET(PDO_PARSER_EOI); }
 	*/	
 }
 
@@ -94,6 +92,7 @@ PDO_API int pdo_parse_params(pdo_stmt_t *stmt, char *inquery, int inquery_len,
 
 	ptr = *outquery;
 	s.cur = inquery;
+	s.end = inquery + inquery_len + 1;
 
 	/* phase 1: look for args */
 	while((t = scan(&s)) != PDO_PARSER_EOI) {
