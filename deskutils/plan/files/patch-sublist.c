--- sublist.c.orig	2017-10-16 23:29:05.000000000 -0700
+++ sublist.c	2022-02-16 13:53:48.815414000 -0800
@@ -20,7 +20,7 @@
 #define CHUNK		100			/* sublist allocation unit */
 
 #ifndef NOREGEX
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #include <regex.h>
 #else
 #define regex_t char
@@ -30,12 +30,14 @@
 #define regex re_exec
 extern char		*regcmp(), *regex(), *__loc1;
 #endif
-#if defined(__EMX__) || defined(__FreeBSD_kernel__)
-#define regcmp regcomp
+#if defined(__EMX__) || defined(__FreeBSD__)
+#define regcmp(a, b) regcomp(a, b, REG_BASIC)
 #define regex regexec
+#ifndef __FreeBSD__
 extern char		*regcmp(), *regex(), *__loc1;
 #endif
 #endif
+#endif
 extern int		search_mode;		/* 0=case, 1=lit, 2=regex */
 extern struct user	*user;			/* user list (from file_r.c) */
 static void		append_entry(struct sublist **, struct entry *);
@@ -93,7 +95,7 @@
 #ifndef NOREGEX
 		regex_t *preg = 0;
 		if (search_mode == 2) {
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 			preg = (regex_t *)malloc(sizeof(regex_t));
 			if (regcomp(preg, key, 0)) {
 #else
@@ -114,7 +116,7 @@
 			    append_entry(&w->sublist, ep);
 #ifndef NOREGEX
 		if (search_mode == 2) {
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 			regfree(preg);
 			free(preg);
 #else
@@ -215,7 +217,7 @@
 
 #ifndef NOREGEX
 	  case 2: {
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 		return(regexec(preg, string, 0, 0, 0) == 0);
 #else
 		char dummy[1024];
