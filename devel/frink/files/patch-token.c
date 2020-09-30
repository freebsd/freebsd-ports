--- token.c.orig	2004-01-22 13:58:48 UTC
+++ token.c
@@ -31,8 +31,6 @@
 #include <malloc.h>
 #endif
 
-extern char *currentfile;
-
 typedef struct tbuff_s
 {
     char *buff;
@@ -77,7 +75,7 @@ static void capTB(TBuff *tp)
     tp->buff[tp->length] ='\0';
 }
 
-static void catTB(TBuff *tp, char *str)
+static void catTB(TBuff *tp, const char *str)
 {
     while (*str)
     {
@@ -86,7 +84,7 @@ static void catTB(TBuff *tp, char *str)
     capTB(tp);
 }
 
-static char *tokenName[] =
+static const char *tokenName[] =
 {
     "ENDF",
     "ENDLINE",
@@ -136,7 +134,7 @@ static Token *concToken(char, char, Input *);
 static Token *callToken(Input *);
 static Token *varToken(Input *);
 
-Token *newToken(TokenType t)
+static Token *newToken(TokenType t)
 {
     Token *tp = malloc(sizeof(Token));
     tp->type = t;
@@ -149,9 +147,9 @@ Token *newToken(TokenType t)
     return tp;
 }
 
-void dumpToken(Token *tk, FILE *ops)
+void dumpToken(const Token *tk, FILE *ops)
 {
-    static char *cval [] =
+    static const char *cval [] =
     {
         "word", "string", "list"
     };
@@ -194,7 +192,7 @@ void dumpToken(Token *tk, FILE *ops)
     }
 }
 
-void fail(Token *tp, char *msg)
+void fail(const Token *tp, const char *msg)
 {
     if (!compout)
     {
@@ -324,7 +322,7 @@ void makeTB(Token *hd, TBuff *tb)
     if (hd != noToken) { makeTB(hd->next, tb); }
 }
 
-void warn(Token *tp, char *msg)
+void warn(const Token *tp, const char *msg)
 {
     Blox *blp = (Blox *) lpeek(blocks);
     TBuff *tbp = newTB(32);
@@ -333,7 +331,7 @@ void warn(Token *tp, char *msg)
     {
         fprintf(stderr, "***");
     }
-    if (currentfile != (char *) 0)
+    if (currentfile != NULL)
     {
         fprintf(stderr, " %s", currentfile);
     }
@@ -376,7 +374,7 @@ void warn(Token *tp, char *msg)
     failed = 1;
 }
 
-static void bwarn(int ln, char *msg)
+static void bwarn(int ln, const char *msg)
 {
     Token *tp = newToken(SP);
     tp->lineNo = ln;
@@ -390,7 +388,7 @@ void streamMore(Input *file)
     file->position = file->text;
     if (file->stream != NULL)
     {
-	file->remaining = fread(file->text, 1, 64*1024, file->stream);
+	file->remaining = fread(file->atext, 1, 64*1024, file->stream);
     }
 }
 
@@ -399,7 +397,7 @@ static int isBlank(char ch)
     return ch == ' ' || ch == '\t';
 }
 
-static char *skipblank(char *cp)
+static const char *skipblank(const char *cp)
 {
     while (isBlank(*cp))
     {
@@ -496,9 +494,9 @@ void freeToken(Token *tp)
 {
     if (tp != noToken)
     {
-	if (tp->text != (char *) 0 && tp->text != tp->little)
+	if (tp->atext != tp->little)
 	{
-	    free(tp->text);
+	    free(tp->atext);
 	}
 	if (tp->sequence) freeToken(tp->sequence);
 	if (tp->next) freeToken(tp->next);
@@ -506,7 +504,7 @@ void freeToken(Token *tp)
     }
 }
 
-static char *filterString(Token *tp, char *txt)
+static char *filterString(Token *tp, const char *txt)
 {
     char *cp = malloc(strlen(txt) + 1), *pt;
     
@@ -555,25 +553,9 @@ Input *tokenise(Token *tp, int expr)
     return file;
 }
 
-Input *ftokenise(char *txt, int length, int lineNo, int expr)
-{
-    Token *tmp = newToken(CONST); /* gash token for filterstring */
-    Input *file = (Input *) malloc(sizeof(Input));
-    file->remaining = length;
-    file->pushed = 0;
-    file->stream = NULL;
-    file->position = file->text = filterString(tmp, txt);
-    file->tcall = 0;
-    file->texpr = expr;
-    file->lineNumber = lineNo;
-    file->lineStart = 1;
-    freeToken(tmp); 
-    return file;
-}
-
 void untokenise(Input *file)
 {
-    free(file->text);
+    free(file->atext);
     free(file);
 }
 
@@ -606,17 +588,17 @@ void tokenPush(Token **tp, Token *v)
     }
 }
 
-static Token *createToken(TokenType t, char *text, Token *nxt)
+static Token *createToken(TokenType t, const char *text, size_t len, Token *nxt)
 {
     Token *tp = newToken(t);
 
-    if ((tp->length = strlen(text)) < (sizeof(tp->little) - 1))
+    if ((tp->length = len) < (sizeof(tp->little) - 1))
     {
 	tp->text = strcpy(tp->little, text);
     }
     else
     {
-	tp->text = newString(text);
+	tp->text = strndup(text, len);
     }
     tp->next = nxt;
     return tp;
@@ -719,7 +701,7 @@ done:
 
 static Token *handleSemi(Input*, char);
 
-Token *stringToken(Input *file, char lst, TokenType res, int term)
+static Token *stringToken(Input *file, char lst, TokenType res, int term)
 {
     int bufSize = 16*1024;
     Token *tp = newToken(res), *nt;
@@ -836,7 +818,7 @@ done:
 }
 
 
-int tokEqual(Token *tp, char *val)
+int tokEqual(const Token *tp, const char *val)
 {
     if (tp != noToken)
     {
@@ -844,7 +826,7 @@ int tokEqual(Token *tp, char *val)
 	{
 	case CONST:
 	case LIST :
-	    return (tp->text != (char *) 0 && strcmp(tp->text, val) == 0);
+	    return (tp->text != NULL && strcmp(tp->text, val) == 0);
 	default:
 	    break;
 	}
@@ -852,7 +834,7 @@ int tokEqual(Token *tp, char *val)
     return 0;
 }
 
-int tokNEqual(Token *tp, char *val, int n)
+static int tokNEqual(const Token *tp, const char *val, int n)
 {
     if (tp != noToken)
     {
@@ -870,7 +852,7 @@ int tokNEqual(Token *tp, char *val, int n)
 
 static int isPragma(TBuff *tp)
 {
-    char *cp;
+    const char *cp;
     
     cp = skipblank(tp->buff + 1); /* start after # character */
     return (strncmp(cp, "PRAGMA", 6) == 0 || strncmp(cp, "FRINK", 5) == 0);
@@ -1251,7 +1233,7 @@ static void handlePragma(Token *tp)
 {
     static struct pragma_s
     {
-        char		*text;
+        const char	*text;
 	enum Pragmas	value;
 	int		nextmode;
     } pragmas[] =
@@ -1263,11 +1245,11 @@ static void handlePragma(Token *tp)
 	{ "set",		0,		2},
 	{ "unused",		0,		3},
 	{ "array",		0,		4},
-	{ (char *) 0,		0,		1},
+	{ NULL,			0,		1},
     };
     struct pragma_s *prp;
     int label, mode = 1;
-    char *cp;
+    const char *cp;
     Token *token, *chars = newToken(CONST);
     Input *pfile;
 
@@ -1347,9 +1329,6 @@ int handle(Token *line)
 {
     Token *hd;
 
-    extern int tclop(Token*, Token*);
-    extern void comment(Token *);
-
     if (line == noToken)
     {
 	if (!minimise)
@@ -1575,7 +1554,7 @@ void lprocess(Token *lst, int nls)
     if (line != noToken) { handle(line); }
 }
 
-Token *accumulate(Input *file, int nl)
+static Token *accumulate(Input *file, int nl)
 {
     Token *line = noToken, *hd = noToken;
     TokenType last = NL;
@@ -1652,16 +1631,16 @@ Token *tokacc(Token *tp, int flag, int nl)
     return lp;
 }
 
-static int chkVarToken(Token *token)
+static int chkVarToken(const Token *token)
 {
     return (token != noToken &&
 	(token->type == VAR || token->type == CALL || token->type == CONC
 	 || token->type == STRING));
 }
 
-int isVarToken(Token *token)
+int isVarToken(const Token *token)
 {
-    char *cp;
+    const char *cp;
     TBuff *tb;
 
     if (token != noToken && token->type == CONC)
@@ -1694,7 +1673,7 @@ int isVarToken(Token *token)
     return chkVarToken(token);
 }
 
-int isSingleCall(Token *token, char *proc)
+int isSingleCall(const Token *token, const char *proc)
 {
     if (token != noToken)
     {
@@ -1715,7 +1694,7 @@ int isSingleCall(Token *token, char *proc)
     return 0;
 }
 
-int isSwitch(Token *token)
+int isSwitch(const Token *token)
 {
     if (token != noToken)
     {
@@ -1739,14 +1718,15 @@ int isSwitch(Token *token)
     return 0;
 }
 
-Token *isArray(Token *tp)
+Token *isArray(const Token *tp)
 {
     Token *res = noToken;
     TBuff *tbp = (TBuff *) 0;
-    char *txt, *cp, ch;
+    const char *txt, *cp;
+    char ch;
     int len;
 
-    if (tp != noToken && (tp->text != (char *) 0 || tp->type == CONC))
+    if (tp != noToken && (tp->text != NULL || tp->type == CONC))
     {
 	switch (tp->type)
 	{
@@ -1776,9 +1756,7 @@ Token *isArray(Token *tp)
 	        ch = *cp;
 	        if (ch == '(')
 		{
-		    *cp = '\0';
-		    res = createToken(CONST, txt, noToken);
-		    *cp = '(';
+		    res = createToken(CONST, txt, cp - txt, noToken);
 		    break;
 		}
 		if (ch == '\0') { break; }
@@ -1790,7 +1768,7 @@ Token *isArray(Token *tp)
     return res;
 }
 
-int constant(Token *tp)
+int constant(const Token *tp)
 {
     return (tp != noToken && (tp->type == CONST || tp->type == LIST));
 }
