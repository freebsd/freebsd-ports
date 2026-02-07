--- src/native/getline.c.orig	2003-01-07 10:14:35 UTC
+++ src/native/getline.c
@@ -41,7 +41,7 @@ char* rl_readline_name;
 
 /********************* exported interface ********************************/
 
-char           *getline();		/* read a line of input */
+char           *get_line();		/* read a line of input */
 void            gl_setwidth();		/* specify width of screen */
 void            gl_histadd();		/* adds entries to hist */
 void		gl_strwidth();		/* to bind gl_strlen */
@@ -136,7 +136,6 @@ extern void     exit();
 #ifndef __convexc__
 extern int      read();
 extern int      kill();
-extern int      ioctl();
 #endif /* not __convexc__ */
 #ifdef POSIX		/* use POSIX interface */
 #include <termios.h>
@@ -387,7 +386,7 @@ gl_init()
         hist_init();
     }
     if (isatty(0) == 0 || isatty(1) == 0)
-	gl_error("\n*** Error: getline(): not interactive, use stdio.\n");
+	gl_error("\n*** Error: get_line(): not interactive, use stdio.\n");
     gl_char_init();
     gl_init_done = 1;
 }
@@ -414,7 +413,7 @@ int  w;
 }
 
 char *
-getline(prompt)
+get_line(prompt)
 char *prompt;
 {
     int             c, loc, tmp;
@@ -585,7 +584,7 @@ int c;
     int  i;
 
     if (gl_cnt >= BUF_SIZE - 1)
-	gl_error("\n*** Error: getline(): input buffer overflow\n");
+	gl_error("\n*** Error: get_line(): input buffer overflow\n");
     if (gl_overwrite == 0 || gl_pos == gl_cnt) {
         for (i=gl_cnt; i >= gl_pos; i--)
             gl_buf[i+1] = gl_buf[i];
@@ -608,7 +607,7 @@ gl_yank()
     if (len > 0) {
 	if (gl_overwrite == 0) {
             if (gl_cnt + len >= BUF_SIZE - 1) 
-	        gl_error("\n*** Error: getline(): input buffer overflow\n");
+	        gl_error("\n*** Error: get_line(): input buffer overflow\n");
             for (i=gl_cnt; i >= gl_pos; i--)
                 gl_buf[i+len] = gl_buf[i];
 	    for (i=0; i < len; i++)
@@ -617,7 +616,7 @@ gl_yank()
 	} else {
 	    if (gl_pos + len > gl_cnt) {
                 if (gl_pos + len >= BUF_SIZE - 1) 
-	            gl_error("\n*** Error: getline(): input buffer overflow\n");
+	            gl_error("\n*** Error: get_line(): input buffer overflow\n");
 		gl_buf[gl_pos + len] = 0;
             }
 	    for (i=0; i < len; i++)
@@ -657,7 +656,7 @@ gl_newline()
     int loc = gl_width - 5;	/* shifts line back to start position */
 
     if (gl_cnt >= BUF_SIZE - 1) 
-        gl_error("\n*** Error: getline(): input buffer overflow\n");
+        gl_error("\n*** Error: get_line(): input buffer overflow\n");
     if (gl_out_hook) {
 	change = gl_out_hook(gl_buf);
         len = strlen(gl_buf);
@@ -916,7 +915,7 @@ char *buf;
     char *p = buf;
     int len;
 
-    /* in case we call gl_histadd() before we call getline() */
+    /* in case we call gl_histadd() before we call get_line() */
     if (gl_init_done < 0) {		/* -1 only on startup */
         hist_init();
         gl_init_done = 0;
