--- cmd1.c.orig	Tue Nov  6 11:53:55 1990
+++ cmd1.c	Sat Aug 17 15:18:01 1996
@@ -882,9 +882,6 @@
 #else
 	msg("%s  (%s)", VERSION, DATE);
 #endif
-#ifdef COMPILED_BY
-	msg("Compiled by %s", COMPILED_BY);
-#endif
 #ifdef CREDIT
 	msg("%s", CREDIT);
 #endif
@@ -893,6 +890,9 @@
 #endif
 #ifdef CVERSION
 	msg("%s", CVERSION);
+#endif
+#ifdef COMPILED_BY
+	msg("Compiled by %s", COMPILED_BY);
 #endif
 #ifdef COPYING
 	msg("%s", COPYING);
