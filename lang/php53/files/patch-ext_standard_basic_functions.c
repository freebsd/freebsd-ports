--- ext/standard/basic_functions.c.orig	2008-06-09 14:06:40.000000000 +0200
+++ ext/standard/basic_functions.c	2008-06-09 14:08:28.000000000 +0200
@@ -87,6 +87,7 @@
 # include <sys/loadavg.h>
 #endif
 
+#define HARTMUT_0
 #ifdef HARTMUT_0
 #include <getopt.h>
 #endif
@@ -3859,7 +3860,7 @@
 		SetEnvironmentVariable(pe->key, "bugbug");
 #endif
 		putenv(pe->previous_value);
-# if defined(PHP_WIN32)
+# if defined(PHP_WIN32) || __FreeBSD_version < 700050
 		efree(pe->previous_value);
 # endif
 	} else {
@@ -4461,7 +4462,7 @@
 		pe.previous_value = NULL;
 		for (env = environ; env != NULL && *env != NULL; env++) {
 			if (!strncmp(*env, pe.key, pe.key_len) && (*env)[pe.key_len] == '=') {	/* found it */
-#if defined(PHP_WIN32)
+#if defined(PHP_WIN32) || __FreeBSD_version < 700050
 				/* must copy previous value because MSVCRT's putenv can free the string without notice */
 				pe.previous_value = estrdup(*env);
 #else
