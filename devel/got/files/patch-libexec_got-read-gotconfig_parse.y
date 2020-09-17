XXX remove first hunk after 0.39
--- libexec/got-read-gotconfig/parse.y.orig	2020-09-14 16:35:22 UTC
+++ libexec/got-read-gotconfig/parse.y
@@ -24,27 +24,17 @@
 %{
 #include <sys/types.h>
 #include <sys/queue.h>
-#include <sys/socket.h>
-#include <sys/stat.h>
 
-#include <netinet/in.h>
-
-#include <arpa/inet.h>
-
 #include <netdb.h>
 
 #include <ctype.h>
 #include <err.h>
 #include <errno.h>
-#include <event.h>
-#include <ifaddrs.h>
-#include <imsg.h>
 #include <limits.h>
 #include <stdarg.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
-#include <syslog.h>
-#include <unistd.h>
 
 #include "got_error.h"
 #include "gotconfig.h"
@@ -71,7 +61,7 @@ int		 igetc(void);
 int		 lgetc(int);
 void		 lungetc(int);
 int		 findeol(void);
-static int	 parseport(char *, long long *);
+static int	 parseport(char *, int64_t *);
 
 TAILQ_HEAD(symhead, sym)	 symhead = TAILQ_HEAD_INITIALIZER(symhead);
 struct sym {
@@ -133,7 +123,7 @@ boolean		: STRING {
 		;
 numberstring	: NUMBER				{
 			char	*s;
-			if (asprintf(&s, "%lld", $1) == -1) {
+			if (asprintf(&s, "%lld", (long long)$1) == -1) {
 				yyerror("string: asprintf");
 				YYERROR;
 			}
@@ -395,7 +385,7 @@ getservice(char *n)
 }
 
 static int
-parseport(char *port, long long *pn)
+parseport(char *port, int64_t *pn)
 {
 	if ((*pn = getservice(port)) == -1) {
 		*pn = 0LL;
