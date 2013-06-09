--- ./cdecl.c.orig	1996-01-16 04:54:46.000000000 +0100
+++ ./cdecl.c	2013-06-10 00:06:29.231069167 +0200
@@ -59,14 +59,22 @@
  */
 
 char cdeclsccsid[] = "@(#)cdecl.c	2.5 1/15/96";
-
+
 #include <stdio.h>
 #include <ctype.h>
+#include <unistd.h>
+
 #if __STDC__ || defined(DOS)
+# if (defined(__unix__) || defined(unix)) && !defined(USG)
+#  include <sys/param.h>
+# endif
 # include <stdlib.h>
 # include <stddef.h>
 # include <string.h>
 # include <stdarg.h>
+# ifndef DOS
+#  include <errno.h>  /* only M$-DOS environments have ``errno'' in stdlib.h */
+# endif /* ndef DOS */
 #else
 # ifndef NOVARARGS
 #  include <varargs.h>
@@ -124,7 +132,6 @@
 
 #if __STDC__
   char *ds(char *), *cat(char *, ...), *visible(int);
-  int getopt(int,char **,char *);
   int main(int, char **);
   int yywrap(void);
   int dostdin(void);
@@ -138,7 +145,9 @@
   void docast(char*, char*, char*, char*);
   void dodexplain(char*, char*, char*, char*);
   void docexplain(char*, char*, char*, char*);
+#if __FreeBSD_version < 430001 || (__FreeBSD_version >= 500000 && __FreeBSD_version < 500019)
   void setprogname(char *);
+#endif
   int dotmpfile(int, char**), dofileargs(int, char**);
 #else
   char *ds(), *cat(), *visible();
@@ -148,7 +157,9 @@
   void unsupp(), notsupported();
   void yyerror();
   void doset(), dodeclare(), docast(), dodexplain(), docexplain();
+#if __FreeBSD_version < 430001 || (__FreeBSD_version >= 500000 && __FreeBSD_version < 500019)
   void setprogname();
+#endif
   int dotmpfile(), dofileargs();
 #endif /* __STDC__ */
   FILE *tmpfile();
@@ -802,6 +813,7 @@
 #endif
 }
 
+#if __FreeBSD_version < 430001 || (__FreeBSD_version  >= 500000 && __FreeBSD_version < 500019)
 /* Save away the name of the program from argv[0] */
 void setprogname(argv0)
 char *argv0;
@@ -841,6 +853,7 @@
 	real_prompt[len+2] = '\0';
     }
 }
+#endif
 
 /* Run down the list of keywords to see if the */
 /* program is being called named as one of them */
