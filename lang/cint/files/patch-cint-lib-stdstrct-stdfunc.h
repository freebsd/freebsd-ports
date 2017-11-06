--- cint/lib/stdstrct/stdfunc.h.orig	2017-10-10 10:28:38.350426000 +0000
+++ cint/lib/stdstrct/stdfunc.h	2017-10-10 10:37:21.898635000 +0000
@@ -70,7 +70,6 @@
 int getc(FILE *fp);
 int getchar(void);
 char *getenv(const char *variable);
-char *gets(char *buffer);
 struct tm* gmtime(time_t *caltime);
 int isalnum(int c);
 int isalpha(int c);
