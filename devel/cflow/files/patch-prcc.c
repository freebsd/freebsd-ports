--- prcc.c.orig	1995-02-16 13:36:48.000000000 +0800
+++ prcc.c	2011-09-16 09:32:36.000000000 +0800
@@ -13,6 +13,7 @@ static char *version = "$Revision: 1.4 $
 #include <string.h>
 #include <stdlib.h>
 #include <assert.h>
+#include <unistd.h>
 
 typedef enum { FALSE=0, TRUE=1 } BOOLEAN;
 
@@ -66,7 +67,7 @@ static void usage(void)
 	exit(2);
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
 	extern int optind;
 	extern char *optarg;
@@ -552,7 +553,7 @@ static char *tag_stack[TAG_STACKSIZE];
 static int tag_sp = 0;
 
 /* pushes buffer onto tag stack */
-static tag_push(char *b)
+static int tag_push(char *b)
 {
 	if (tag_sp < TAG_STACKSIZE
 	&& (tag_stack[tag_sp] = (char *) malloc(strlen(b) + 1)) != NULL) {
@@ -563,7 +564,7 @@ static tag_push(char *b)
 }
 
 /* pops value off tag stack to buffer */
-static tag_pop(char *b)
+static int tag_pop(char *b)
 {
 	if (tag_sp) {
 		strcpy(b, tag_stack[--tag_sp]);
@@ -612,7 +613,7 @@ static tag_pop(char *b)
  * NAME [a-z]+          (really any valid name that isn't reserved word) */
 
 /* returns token of next item in input */
-static lex_gettoken(void)
+static int lex_gettoken(void)
 {
 	static int expanded = 0;	/* boolean: ARGSEND expanded? */
 
@@ -823,7 +824,7 @@ static int cpp_prevch;		/* an ungotten c
 static int cpp_refsok;		/* boolean: can we echo characters out to "refs"? */
 
 /* This function opens the file & resets variables */
-static cpp_open(char *name)
+static int cpp_open(char *name)
 			/* name of source file to be opened */
 {
 	/* use the lower-level file_open function to open the file */
@@ -837,7 +838,7 @@ static cpp_open(char *name)
 }
 
 /* returns next nonwhite-space character */
-static cpp_nonwhite(void)
+static int cpp_nonwhite(void)
 {
 	int ch;
 	int next;
@@ -865,7 +866,7 @@ static cpp_nonwhite(void)
 
 
 /* This function returns the next character which isn't part of a directive */
-static cpp_getc(void)
+static int cpp_getc(void)
 {
 	int ch;			/* the next input character */
 	int i = 0;
@@ -992,7 +993,7 @@ static int file_getc(void)
 }
 
 /* This function ungets a character from the current source file */
-static file_ungetc(int ch)
+static int file_ungetc(int ch)
 			/* character to be ungotten */
 {
 	return file_prevch = ch;
