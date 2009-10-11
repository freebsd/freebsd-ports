--- sublist.c.orig	Sun May  2 12:23:15 1999
+++ sublist.c	Thu Jun 17 13:09:05 1999
@@ -23,7 +23,7 @@
 #define regcmp re_comp
 #define regex re_exec
 #endif
-#if defined(linux) || defined(__EMX__)
+#if defined(linux) || defined(__EMX__) || defined(POSIX_REGEX)
 #define regcmp regcomp
 #define regex regexec
 #endif
