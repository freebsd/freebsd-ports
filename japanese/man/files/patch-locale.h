--- man/locale.h	2001/07/17 01:42:54
+++ man/locale.h	2001/12/13 02:17:39
@@ -20,5 +20,5 @@
 char *directive(int);
 int try_section_ml(char *, char *, char *, int, int);
 int try_section(char *, char *, char *, int);
-int man_ml(char *);
+int man_ml(char *, int);
 int man(char *);
