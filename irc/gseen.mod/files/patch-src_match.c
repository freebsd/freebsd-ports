$NetBSD: patch-src_match.c,v 1.1 2012/11/16 00:35:28 joerg Exp $

--- src/match.c.orig	2012-11-15 10:29:42.000000000 +0000
+++ src/match.c
@@ -367,7 +367,7 @@ int cidr_match(char *m, char *n, int cou
 /* Inline for cron_match (obviously).
  * Matches a single field of a crontab expression.
  */
-inline int cron_matchfld(char *mask, int match)
+static inline int cron_matchfld(char *mask, int match)
 {
   int skip = 0, f, t;
   char *p, *q;
