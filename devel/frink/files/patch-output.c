--- output.c.orig	2002-12-11 23:05:16 UTC
+++ output.c
@@ -43,10 +43,10 @@ static int olead	= 0;		/* number of spaces wanted at s
 
 static TokenType olast	= HEAD;
 
-static Token nlToken	= {BLANK, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token startToken	= {START, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token contToken	= {CONT, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token spToken	= {SP, CNSTWORD, 0, " ", 1, (Token *) 0, (Token *) 0};
+static Token nlToken	= {.type = BLANK, .ckind = CNSTWORD};
+static Token startToken	= {.type = START, .ckind = CNSTWORD};
+static Token contToken	= {.type = CONT, .ckind = CNSTWORD};
+static Token spToken	= {.type = SP, .ckind = CNSTWORD, .text = " ", .length = 1};
 
 void initOutput(void)
 {
@@ -226,7 +226,7 @@ static void termline(void)
     }
 }
 
-static void printkn(char *txt, int length, int keepnl)
+static void printkn(const char *txt, int length, int keepnl)
 {
     char *cp;
     int l;
@@ -251,7 +251,7 @@ static void printkn(char *txt, int length, int keepnl)
     }
 }
 
-static void printn(char *txt, int len)
+static void printn(const char *txt, int len)
 {
     if (!testonly)
     {
@@ -259,12 +259,12 @@ static void printn(char *txt, int len)
     }
 }
 
-static void print(char *txt)
+static void print(const char *txt)
 {
     printn(txt, strlen(txt));
 }
 
-static void brace(char *t)
+static void brace(const char *t)
 {
     char *cp, *bp;
     while ((cp = strpbrk(t, "{}")) != (char *) 0)
@@ -377,10 +377,10 @@ static void putString(Token *seq)
     if (qts) { printn("\"", 1); }
 }
 
-static Token dollarToken = {DOLLAR, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token endlineToken = {ENDLINE, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token lbrackToken = {LBRACK, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token rbrackToken = {RBRACK, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
+static Token dollarToken = {.type = DOLLAR, .ckind = CNSTWORD};
+static Token endlineToken = {.type = ENDLINE, .ckind = CNSTWORD};
+static Token lbrackToken = {.type = LBRACK, .ckind = CNSTWORD};
+static Token rbrackToken = {.type = RBRACK, .ckind = CNSTWORD};
 
 void output(Token *token, int compress)
 {
