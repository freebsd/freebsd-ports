--- server/dia/main.c.orig	2020-08-22 22:22:28 UTC
+++ server/dia/main.c
@@ -76,7 +76,7 @@ static char *AuServerName(void);
 extern char *display;
 
 static int restart = 0;
-FILE *yyin;                     /* for the config parser */
+extern FILE *yyin;                     /* for the config parser */
 
 void
 NotImplemented()
