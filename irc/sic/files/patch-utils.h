--- utils.h.orig	2000-07-31 22:37:23 UTC
+++ utils.h
@@ -7,7 +7,6 @@
 #ifndef _utils_h_
 #define _utils_h_
 
-extern	char *	strcasestr(const char *, const char *);
 extern	int	rmatch(const char *, const char *);
 extern	char *	my_cftime(char *, const int len, const char *, const time_t);
 extern	char *	my_strftime(char *, const int len, const char *);
