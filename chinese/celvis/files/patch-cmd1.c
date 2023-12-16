--- cmd1.c.orig	1990-11-06 19:53:55 UTC
+++ cmd1.c
@@ -882,9 +882,6 @@ void cmd_version(frommark, tomark, cmd, bang, extra)
 #else
 	msg("%s  (%s)", VERSION, DATE);
 #endif
-#ifdef COMPILED_BY
-	msg("Compiled by %s", COMPILED_BY);
-#endif
 #ifdef CREDIT
 	msg("%s", CREDIT);
 #endif
@@ -893,6 +890,9 @@ void cmd_version(frommark, tomark, cmd, bang, extra)
 #endif
 #ifdef CVERSION
 	msg("%s", CVERSION);
+#endif
+#ifdef COMPILED_BY
+	msg("Compiled by %s", COMPILED_BY);
 #endif
 #ifdef COPYING
 	msg("%s", COPYING);
