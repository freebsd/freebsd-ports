--- source/term.c.orig	Tue Aug 22 02:48:46 2000
+++ source/term.c	Mon Dec  4 03:44:17 2000
@@ -9,6 +9,7 @@
  */
 
 #define __need_putchar_x__
+#define __need_putchars_x__
 #define __need_term_flush__
 #include "irc.h"
 #include "ircaux.h"
@@ -17,6 +18,7 @@
 #include "window.h"
 #include "screen.h"
 #include "output.h"
+#include "kanji.h"
 
 /*
  * If "HAVE_TERMINFO" is #define'd then we will use terminfo type function
@@ -618,8 +620,10 @@
  * we need to worry about here is making sure nothing suspcious, like an
  * escape, makes its way to the output stream.
  */
-void	term_putchar (unsigned char c)
+void	term_putchar (unsigned char c1, unsigned char c2)
 {
+        unsigned char c = c1;
+	
 	if (!term_echo_flag)
 	{
 		putchar_x(' ');
@@ -656,12 +660,20 @@
 		putchar_x('?');
 		term_standout_off();
 	}
-
+	
+	/* add */
+	else if (ISKANJI(c1) && ISKANJI(c2)) {
+	  unsigned char k[3];
+	  /* unsigned char tmp[10]; */
+	  
+	  k[0] = c1; k[1] = c2; k[2] = '\0';
+	  putchars_x(k);
+	}
 	/*
 	 * Everything else is passed through.
 	 */
-	else
-		putchar_x(c);
+	else 
+	  putchar_x(c);
 }
 
 
@@ -1303,7 +1315,7 @@
 	else if (current_term->TI_ich)
 		tputs_x (tparm(current_term->TI_ich, 1));
 
-	term_putchar (c);
+	term_putchar (c, '\0');
 
 	if (current_term->TI_rmir)
 		tputs_x(current_term->TI_rmir);
