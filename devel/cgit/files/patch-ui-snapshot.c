--- ui-snapshot.c.orig	2016-12-01 13:52:53 UTC
+++ ui-snapshot.c
@@ -37,7 +37,7 @@ static int write_archive_type(const char
 	/* argv_array guarantees a trailing NULL entry. */
 	memcpy(nargv, argv.argv, sizeof(char *) * (argv.argc + 1));
 
-	result = write_archive(argv.argc, nargv, NULL, 1, NULL, 0);
+	result = write_archive(argv.argc, nargv, NULL, NULL, 0);
 	argv_array_clear(&argv);
 	free(nargv);
 	return result;
