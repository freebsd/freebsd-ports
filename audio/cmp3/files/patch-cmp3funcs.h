--- cmp3funcs.h.orig	2001-06-13 20:13:27 UTC
+++ cmp3funcs.h
@@ -64,7 +64,7 @@ extern Sigfunc *Signal(int signo, Sigfun
 extern char *Strdup(const char *string);
 extern int Strcmp(const char *str1, const char *str2);
 extern int Strncmp(const char *str1, const char *str2, int num);
-extern int getline(char *var, int  maxbuf, FILE *input);
+extern int get_line(char *var, int  maxbuf, FILE *input);
 
 extern void *Malloc(size_t size);
 
@@ -86,4 +86,4 @@ extern void voldown();
 /* cmp3id3.c */
 extern int readid3(id3info_t *songinfo, char *songfilename);
 
-/* EOF */
\ No newline at end of file
+/* EOF */
