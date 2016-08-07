--- cdecl.c.orig	1996-01-16 03:54:46 UTC
+++ cdecl.c
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
@@ -90,7 +98,7 @@ void free(), exit(), perror();
 #ifdef USE_READLINE
 # include <readline/readline.h>
   /* prototypes for functions related to readline() */
-  char * getline();
+  char * get_line();
   char ** attempt_completion(char *, int, int);
   char * keyword_completion(char *, int);
   char * command_completion(char *, int);
@@ -124,7 +132,6 @@ char real_prompt[MAX_NAME+3];
 
 #if __STDC__
   char *ds(char *), *cat(char *, ...), *visible(int);
-  int getopt(int,char **,char *);
   int main(int, char **);
   int yywrap(void);
   int dostdin(void);
@@ -138,7 +145,9 @@ char real_prompt[MAX_NAME+3];
   void docast(char*, char*, char*, char*);
   void dodexplain(char*, char*, char*, char*);
   void docexplain(char*, char*, char*, char*);
+#if !defined __FreeBSD__ && !defined __DragonFly__
   void setprogname(char *);
+#endif
   int dotmpfile(int, char**), dofileargs(int, char**);
 #else
   char *ds(), *cat(), *visible();
@@ -148,7 +157,9 @@ char real_prompt[MAX_NAME+3];
   void unsupp(), notsupported();
   void yyerror();
   void doset(), dodeclare(), docast(), dodexplain(), docexplain();
+#if !defined __FreeBSD__ && !defined __DragonFly__
   void setprogname();
+#endif
   int dotmpfile(), dofileargs();
 #endif /* __STDC__ */
   FILE *tmpfile();
@@ -375,7 +386,7 @@ char *options[] = {
 static char *line_read = NULL;
 
 /* Read a string, and return a pointer to it.  Returns NULL on EOF. */
-char * getline ()
+char * get_line ()
 {
   /* If the buffer has already been allocated, return the memory
      to the free pool. */
@@ -802,6 +813,7 @@ void prompt()
 #endif
 }
 
+#if !defined __FreeBSD__ && !defined __DragonFly__
 /* Save away the name of the program from argv[0] */
 void setprogname(argv0)
 char *argv0;
@@ -841,6 +853,7 @@ char *argv0;
 	real_prompt[len+2] = '\0';
     }
 }
+#endif
 
 /* Run down the list of keywords to see if the */
 /* program is being called named as one of them */
@@ -887,7 +900,7 @@ int dostdin()
 
 	if (!quiet) (void) printf("Type `help' or `?' for help\n");
 	ret = 0;
-	while ((line = getline())) {
+	while ((line = get_line())) {
 	    if (!strcmp(line, "quit") || !strcmp(line, "exit")) {
 		free(line);
 		return ret;
