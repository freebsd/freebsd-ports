--- token.h.orig	2002-12-11 22:20:34 UTC
+++ token.h
@@ -18,11 +18,14 @@
 
 typedef struct input_s
 {
-    char *position;
+    const char *position;
     int	 remaining;
     int  pushed;
     char back[16];
-    char *text;
+    union {
+        const char *text; /* Use const in most cases */
+	char *atext;
+    };
     FILE *stream;
     int tcall;
     int texpr;
@@ -48,8 +51,11 @@ typedef struct token_s
     TokenType type;
     ConstType ckind;
     int isconc;
-    char *text;
-    int length;
+    union {
+        const char *text;
+        char *atext;
+    };
+    size_t length;
     struct token_s *sequence;
     struct token_s *next;
     char little[32];
@@ -69,12 +75,21 @@ extern void freeToken(Token *);
 extern void lprocess(Token*, int);
 extern void makeCall(Token*, Token*);
 extern void body(Token *, int, int);
+extern void comment(Token *);
 
 extern void output(Token *, int);
 extern void blank(void);
-extern void warn(Token *, char *);
-extern void fail(Token *, char *);
+extern void warn(const Token *, const char *);
+extern void fail(const Token *, const char *);
 
-extern Token *isArray(Token *);
-extern int constant(Token *tp);
+extern Token *isArray(const Token *);
+extern int constant(const Token *tp);
+extern int tclop(Token *hd, Token *line);
+extern void streamMore(Input *file);
+extern int handle(Token *line);
+extern void sprocess(Token *lst, int nls);
+extern void dumpToken(const Token *tk, FILE *ops);
+extern Token *tokenPop(Token **);
+extern void freeToken(Token *);
+
 #endif
