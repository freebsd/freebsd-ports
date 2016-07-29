--- src/native/getline.h.orig	2003-01-07 10:14:35 UTC
+++ src/native/getline.h
@@ -9,7 +9,7 @@
 
 extern char* rl_readline_name;                  /* unused by getline   */
 #define add_history(buffer) gl_histadd(buffer)
-#define readline(buffer)    getline(buffer)
+#define readline(buffer)    get_line(buffer)
 #define clear_history()     hist_init()
 #define using_history()     hist_init()
 
@@ -18,7 +18,7 @@ extern char* rl_readline_name;          
 
 typedef size_t (*gl_strwidth_proc)(char *);
 
-char           *getline(char *);		/* read a line of input */
+char           *get_line(char *);		/* read a line of input */
 void            gl_setwidth(int);		/* specify width of screen */
 void            gl_histadd(char *);		/* adds entries to hist */
 void		gl_strwidth(gl_strwidth_proc);	/* to bind gl_strlen */
@@ -30,7 +30,7 @@ extern int	(*gl_tab_hook)(char *, int, i
 
 #else	/* not __STDC__ */
 
-char           *getline();	
+char           *get_line();	
 void            gl_setwidth();
 void            gl_histadd();
 void		gl_strwidth();
