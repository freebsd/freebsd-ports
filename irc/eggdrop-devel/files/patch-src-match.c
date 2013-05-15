--- src/match.c.orig	2013-05-13 15:17:47.000000000 +0200
+++ src/match.c	2013-05-13 15:17:24.000000000 +0200
@@ -367,7 +367,7 @@
 /* Inline for cron_match (obviously).
  * Matches a single field of a crontab expression.
  */
-inline int cron_matchfld(char *mask, int match)
+int cron_matchfld(char *mask, int match)
 {
   int skip = 0, f, t;
   char *p, *q;
