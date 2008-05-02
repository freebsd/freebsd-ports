--- ext/standard/basic_functions.c.orig	2008-05-02 08:44:06.000000000 +0200
+++ ext/standard/basic_functions.c	2008-05-02 08:54:00.000000000 +0200
@@ -87,6 +87,7 @@
 # include <sys/loadavg.h>
 #endif
 
+#define HARTMUT_0
 #ifdef HARTMUT_0
 #include <getopt.h>
 #endif
@@ -3861,9 +3862,7 @@
 		SetEnvironmentVariable(pe->key, "bugbug");
 #endif
 		putenv(pe->previous_value);
-# if defined(PHP_WIN32)
 		efree(pe->previous_value);
-# endif
 	} else {
 # if HAVE_UNSETENV
 		unsetenv(pe->key);
@@ -4463,12 +4462,8 @@
 		pe.previous_value = NULL;
 		for (env = environ; env != NULL && *env != NULL; env++) {
 			if (!strncmp(*env, pe.key, pe.key_len) && (*env)[pe.key_len] == '=') {	/* found it */
-#if defined(PHP_WIN32)
 				/* must copy previous value because MSVCRT's putenv can free the string without notice */
 				pe.previous_value = estrdup(*env);
-#else
-				pe.previous_value = *env;
-#endif
 				break;
 			}
 		}
