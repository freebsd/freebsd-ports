--- echolinux/echolinux.h.orig	Sun Dec 22 04:11:34 2002
+++ echolinux/echolinux.h	Mon Jul  5 00:16:32 2004
@@ -11,22 +11,17 @@
 #define PORT_BASE 5198
 
 
-struct termio term_params, old_term_params;
+struct termios term_params, old_term_params;
 
 void raw_tty(int flag){
 
   if(flag){
-  ioctl(fileno(stdin), TCGETA, &old_term_params);
+  tcgetattr(fileno(stdin), &old_term_params);
   term_params = old_term_params;
-  term_params.c_iflag &= ~(ICRNL|IXON|IXOFF);  /* no cr translation */
-  term_params.c_iflag &= ~(ISTRIP);   /* no stripping of high order bit */
-  term_params.c_oflag &= ~(OPOST);    /* no output processing */       
-  term_params.c_lflag &= ~(ISIG|ICANON|ECHO); /* raw mode */
-  term_params.c_cc[VMIN] = 0;  /* satisfy read after 1 char */
-  term_params.c_cc[VTIME] = 0;  /* satisfy read after 1 char */
-  ioctl(fileno(stdin), TCSETAF, &term_params);
+  cfmakeraw(&term_params);
+  tcsetattr(fileno(stdin), TCSAFLUSH, &term_params);
   } else{
-  ioctl(fileno(stdin), TCSETAF, &old_term_params);
+  tcsetattr(fileno(stdin), TCSAFLUSH, &old_term_params);
   }
 }
 
