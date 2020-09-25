--- libexec/got-read-gotconfig/parse.y.orig	2020-09-25 11:58:47 UTC
+++ libexec/got-read-gotconfig/parse.y
@@ -63,7 +63,7 @@ int		 igetc(void);
 int		 lgetc(int);
 void		 lungetc(int);
 int		 findeol(void);
-static int	 parseport(char *, long long *);
+static int	 parseport(char *, int64_t *);
 
 TAILQ_HEAD(symhead, sym)	 symhead = TAILQ_HEAD_INITIALIZER(symhead);
 struct sym {
@@ -125,7 +125,7 @@ boolean		: STRING {
 		;
 numberstring	: NUMBER				{
 			char	*s;
-			if (asprintf(&s, "%lld", $1) == -1) {
+			if (asprintf(&s, "%lld", (long long)$1) == -1) {
 				yyerror("string: asprintf");
 				YYERROR;
 			}
@@ -387,7 +387,7 @@ getservice(char *n)
 }
 
 static int
-parseport(char *port, long long *pn)
+parseport(char *port, int64_t *pn)
 {
 	if ((*pn = getservice(port)) == -1) {
 		*pn = 0LL;
