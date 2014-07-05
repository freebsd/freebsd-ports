--- filters/filters.h.orig	2012-02-18 01:53:10.000000000 +0000
+++ filters/filters.h
@@ -205,7 +205,7 @@ extern int yywrap(void);
  * workaround for "developers" who don't use compiler-warnings...
  * perhaps by the time "new" flex merits the term "beta", they'll fix this:
  */
-#if defined(FLEX_BETA)
+#if defined(FLEX_BETA) && !defined(__DragonFly__)
 extern FILE *yyget_in (void);
 extern FILE *yyget_out (void);
 extern char *yyget_text (void);
