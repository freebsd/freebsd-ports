--- src/regex.c.orig	Sun Apr 18 22:19:13 2004
+++ src/regex.c	Sun Apr 18 22:18:40 2004
@@ -1322,7 +1322,7 @@
    exactly that if always used MAX_FAILURE_SPACE each time we failed.
    This is a variable only so users of regex can assign to it; we never
    change it ourselves.  */
-#if defined (MATCH_MAY_ALLOCATE)
+#if defined (MATCH_MAY_ALLOCATE) || defined (REGEX_MALLOC)
 /* 4400 was enough to cause a crash on Alpha OSF/1,
    whose default stack limit is 2mb.  */
 int re_max_failures = 20000;
