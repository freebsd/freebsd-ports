--- ext/standard/basic_functions.c.orig	2013-12-10 23:31:06.000000000 +0000
+++ ext/standard/basic_functions.c	2013-12-13 21:50:25.289258456 +0000
@@ -3429,7 +3429,7 @@ static void php_putenv_destructor(putenv
 		SetEnvironmentVariable(pe->key, "bugbug");
 #endif
 		putenv(pe->previous_value);
-# if defined(PHP_WIN32)
+# if defined(PHP_WIN32) || __FreeBSD_version < 700050
 		efree(pe->previous_value);
 # endif
 	} else {
@@ -4114,7 +4114,7 @@ PHP_FUNCTION(putenv)
 		pe.previous_value = NULL;
 		for (env = environ; env != NULL && *env != NULL; env++) {
 			if (!strncmp(*env, pe.key, pe.key_len) && (*env)[pe.key_len] == '=') {	/* found it */
-#if defined(PHP_WIN32)
+#if defined(PHP_WIN32) || __FreeBSD_version < 700050
 				/* must copy previous value because MSVCRT's putenv can free the string without notice */
 				pe.previous_value = estrdup(*env);
 #else
