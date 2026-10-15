--- widget/initapp.c.orig	2026-10-15 18:46:12 UTC
+++ widget/initapp.c
@@ -233,7 +233,6 @@ int cooledit_regex_get_utf8_or_ascii (void)
 #ifndef NO_TTF
 
 /* For FreeBSD package maintainer: remove this next line */
-#undef __FreeBSD__
 
 #ifndef __FreeBSD__
 
