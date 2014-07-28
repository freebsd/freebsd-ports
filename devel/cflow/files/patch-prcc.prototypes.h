--- prcc.prototypes.h.orig	1994-10-31 03:32:00.000000000 +0800
+++ prcc.prototypes.h	2011-09-16 09:33:20.000000000 +0800
@@ -1,23 +1,22 @@
 /* prcc.c */
 static void usage(void);
-void main(int argc, char **argv);
+int main(int argc, char **argv);
 static void ctags(void);
 static void maketag(int scope, int iscall);
-static tag_push(char *b);
-static tag_pop(char *b);
-static lex_gettoken(void);
-static cpp_open(char *name);
-static cpp_nonwhite(void);
-static cpp_getc(void);
+static int tag_push(char *b);
+static int tag_pop(char *b);
+static int lex_gettoken(void);
+static int cpp_open(char *name);
+static int cpp_nonwhite(void);
+static int cpp_getc(void);
 static int cpp_ungetc(int ch);
 static int file_open(char *name);
 static int file_getc(void);
-static file_ungetc(int ch);
+static int file_ungetc(int ch);
 static void per_file_init(void);
 static void per_file_cleanup(void);
 static BOOLEAN name_redefined(int isvar);
-static void display_keywords(const char *type, char **words);
-static void show_all_keywords(void);
+static void show_all_lists(void);
 static BOOLEAN name_to_list(name_t **lp, char *lex_name);
 static BOOLEAN name_from_list(name_t **lp);
 static BOOLEAN name_in_list(name_t *l);
