--- engdic.c.orig	1999-09-05 22:48:50.000000000 -0400
+++ engdic.c	2013-08-30 13:54:53.000000000 -0400
@@ -29,6 +29,7 @@
 #include <termio.h>
 #endif
 
+#include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -49,7 +50,17 @@
 char get_command(void) ;
 struct size_buf get_term(void);
 
+void clear_eol(void) ;
+void deinit(void) ;
+void flush(void) ;
+char getchr(void) ;
+void init(void) ;
+void lower_left(void) ;
+int putchr(int) ;
 char putstr (char *s) ;
+void raw_mode(int on) ;
+void so_enter(void) ;
+void so_exit(void) ;
 char sep[] = ":" ;
 static int line = 0 ;
 
@@ -68,7 +79,7 @@
     struct stat sb ;
     
     // type of gzip file //
-    register gzFile *gzfp ;
+    register gzFile gzfp ;
     
 
     if (argc > 1) {
@@ -182,7 +193,7 @@
     register int check_cols_count = 0 ;
     char ch ;
     
-    if (tk == NULL || tk2 == NULL) return ;
+    if (tk == NULL || tk2 == NULL) return 0 ;
     
     putstr(WORD_COLOR) ; putstr("[ ") ; putstr(tk); putchr(']') ;
     putstr(NO_COLOR) ; putstr("\r\n") ;
