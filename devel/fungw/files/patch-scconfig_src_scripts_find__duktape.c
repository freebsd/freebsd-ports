--- scconfig/src/scripts/find_duktape.c.orig	2022-05-06 14:34:12 UTC
+++ scconfig/src/scripts/find_duktape.c
@@ -44,7 +44,7 @@ int find_script_duktape(const char *name, int logdepth
 	logdepth++;
 
 	/* Look at the standard place */
-	if (try_icl(logdepth, "libs/script/duktape", test_c, NULL, NULL, "-lduktape -lm")) return 0;
+	if (try_icl(logdepth, "libs/script/duktape", test_c, NULL, "-I%%LOCALBASE%%/include", "-L%%LOCALBASE%%/lib -lduktape -lm")) return 0;
 
 	return try_fail(logdepth, "libs/script/duktape");
 }
