--- include/term.h.orig	Thu Feb 10 05:07:39 2000
+++ include/term.h	Mon Dec  4 03:44:17 2000
@@ -30,6 +30,11 @@
 static int putchar_x (int c) { return fputc((int) c, current_ftarget ); }
 #endif
 
+#ifdef __need_putchars_x__
+__inline__
+static int putchars_x (char* c) { return fputs( c, current_ftarget ); }
+#endif
+
 #ifdef __need_term_flush__
 __inline__
 static void term_flush (void) { fflush( current_ftarget ); }
@@ -632,7 +637,7 @@
 	int		term_init 		(void);
 	int		term_resize 		(void);
 	void		term_pause 		(char, char *);
-	void		term_putchar 		(unsigned char);
+	void		term_putchar 		(unsigned char, unsigned char);
 	void		term_scroll 		(int, int, int);
 	void		term_insert 		(unsigned char);
 	void		term_delete 		(int);
