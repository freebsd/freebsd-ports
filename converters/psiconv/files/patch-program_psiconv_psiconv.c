--- program/psiconv/psiconv.c.orig	2020-08-28 22:46:41 UTC
+++ program/psiconv/psiconv.c
@@ -44,6 +44,8 @@
 #include "psiconv.h"
 #include "gen.h"
 
+psiconv_list fileformat_list; /* of struct psiconv_fileformat */
+
 static void print_help(void);
 static void print_version(void);
 static void strtoupper(char *str);
