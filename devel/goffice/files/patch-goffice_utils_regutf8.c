--- goffice/utils/regutf8.c.orig	2009-09-05 23:52:09.000000000 +0000
+++ goffice/utils/regutf8.c	2013-03-13 17:22:39.000000000 +0000
@@ -21,11 +21,7 @@ void
 go_regfree (GORegexp *gor)
 {
 	if (gor->ppcre) {
-#ifdef HAVE_G_REGEX_ERROR_STRAY_BACKSLASH
 		g_regex_unref (gor->ppcre);
-#else
-		pcre_free (gor->ppcre);
-#endif
 		gor->ppcre = NULL;
 	}
 }
@@ -70,7 +66,6 @@ go_regerror (int errcode, const GORegexp
 int
 go_regcomp (GORegexp *gor, const char *pat, int cflags)
 {
-#ifdef HAVE_G_REGEX_ERROR_STRAY_BACKSLASH
 	GError *error = NULL;
 	GRegex *r;
 	int coptions =
@@ -119,7 +114,7 @@ go_regcomp (GORegexp *gor, const char *p
 		gor->nosub = (cflags & GO_REG_NOSUB) != 0;
 		return 0;
 	}
-#else
+#if 0
 	const char *errorptr;
 	int errorofs, errorcode;
 	pcre *r;
@@ -167,7 +162,6 @@ int
 go_regexec (const GORegexp *gor, const char *txt,
 	    size_t nmatch, GORegmatch *pmatch, int eflags)
 {
-#ifdef HAVE_G_REGEX_ERROR_STRAY_BACKSLASH
 	int eoptions =
 		((eflags & GO_REG_NOTBOL) ? G_REGEX_MATCH_NOTBOL : 0) |
 		((eflags & GO_REG_NOTEOL) ? G_REGEX_MATCH_NOTEOL : 0);
@@ -196,7 +190,7 @@ go_regexec (const GORegexp *gor, const c
 		g_match_info_free (match_info);
 
 	return matched ? GO_REG_NOERROR : GO_REG_NOMATCH;
-#else
+#if 0
 	size_t txtlen = strlen (txt);
 	int eoptions =
 		((eflags & GO_REG_NOTBOL) ? PCRE_NOTBOL : 0) |
