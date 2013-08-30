--- screen.c.orig	1999-09-05 22:48:35.000000000 -0400
+++ screen.c	2013-08-30 13:56:48.000000000 -0400
@@ -45,6 +45,8 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <term.h>
+#include <unistd.h>
 
 #define TERMIOS 1
 
@@ -53,7 +55,9 @@
 #else
 #if TERMIOS
 #include <termios.h>
+#ifndef TAB3
 #define TAB3 0
+#endif
 #include <sys/ioctl.h>
 #else
 #include <sgtty.h>
@@ -75,6 +79,7 @@
 #endif
 
 #include <setjmp.h>
+#include <stdlib.h>
 #include "engdic.h"
 
 volatile int reading;
@@ -131,8 +136,12 @@
 /*extern*/ char PC;		/* Pad character */
 
 int back_scroll;
-char *tgetstr();
-char *tgoto();
+
+void bo_exit(void);
+void flush(void);
+int iread(int, char *, int);
+void so_exit(void);
+void ul_exit(void);
 
 /*
  * Change terminal to "raw mode", or restore to "normal" mode.
@@ -145,8 +154,7 @@
  *	   etc. are NOT disabled.
  * It doesn't matter whether an input \n is mapped to \r, or vice versa.
  */
-raw_mode(on)
-	int on;
+void raw_mode(int on)
 {
 #if TERMIO || TERMIOS
 
@@ -245,7 +253,7 @@
 /*
  * Get terminal capabilities via termcap.
  */
-struct size_buf get_term()
+struct size_buf get_term(void)
 {
 	char termbuf[2048];
 	char *sp;
@@ -260,8 +268,6 @@
 #endif
 	static char sbuf[1024];
 
-	char *getenv(), *strcpy();
-	
 	struct size_buf sz_buf ;
 
 	/*
@@ -470,12 +476,12 @@
  * terminal-specific screen manipulation.
  */
 
-int putchr();
+int putchr(int);
 
 /*
  * Initialize terminal
  */
-init()
+void init(void)
 {
 	tputs(sc_init, sc_height, putchr);
 }
@@ -483,7 +489,7 @@
 /*
  * Deinitialize terminal
  */
-deinit()
+void deinit(void)
 {
 	tputs(sc_deinit, sc_height, putchr);
 }
@@ -491,7 +497,7 @@
 /*
  * Home cursor (move to upper left corner of screen).
  */
-home()
+void home(void)
 {
 	tputs(sc_home, 1, putchr);
 }
@@ -500,13 +506,13 @@
  * Add a blank line (called with cursor at home).
  * Should scroll the display down.
  */
-add_line()
+void add_line(void)
 {
 	tputs(sc_addline, sc_height, putchr);
 }
 
 int short_file;				/* if file less than a screen */
-lower_left()
+void lower_left(void)
 {
 	if (short_file) {
 		putchr('\r');
@@ -517,17 +523,9 @@
 }
 
 /*
- * Ring the terminal bell.
- */
-bell()
-{
-	putchr('\7');
-}
-
-/*
  * Clear the screen.
  */
-clear()
+void clear(void)
 {
 	if (mode_flags & M_SO)
 		so_exit();
@@ -542,7 +540,7 @@
  * Clear from the cursor to the end of the cursor's line.
  * {{ This must not move the cursor. }}
  */
-clear_eol()
+void clear_eol(void)
 {
 	if (mode_flags & M_SO)
 		so_exit();
@@ -556,7 +554,7 @@
 /*
  * Begin "standout" (bold, underline, or whatever).
  */
-so_enter()
+void so_enter(void)
 {
 	tputs(sc_s_in, 1, putchr);
 	mode_flags |= M_SO;
@@ -565,7 +563,7 @@
 /*
  * End "standout".
  */
-so_exit()
+void so_exit(void)
 {
 	tputs(sc_s_out, 1, putchr);
 	mode_flags &= ~M_SO;
@@ -575,7 +573,7 @@
  * Begin "underline" (hopefully real underlining,
  * otherwise whatever the terminal provides).
  */
-ul_enter()
+void ul_enter(void)
 {
 	tputs(sc_u_in, 1, putchr);
 	mode_flags |= M_UL;
@@ -584,7 +582,7 @@
 /*
  * End "underline".
  */
-ul_exit()
+void ul_exit(void)
 {
 	tputs(sc_u_out, 1, putchr);
 	mode_flags &= ~M_UL;
@@ -593,7 +591,7 @@
 /*
  * Begin "bold"
  */
-bo_enter()
+void bo_enter(void)
 {
 	tputs(sc_b_in, 1, putchr);
 	mode_flags |= M_BO;
@@ -602,7 +600,7 @@
 /*
  * End "bold".
  */
-bo_exit()
+void bo_exit(void)
 {
 	tputs(sc_b_out, 1, putchr);
 	mode_flags &= ~M_BO;
@@ -612,7 +610,7 @@
  * Erase the character to the left of the cursor
  * and move the cursor left.
  */
-backspace()
+void backspace(void)
 {
 	/*
 	 * Try to erase the previous character by overstriking with a space.
@@ -625,28 +623,27 @@
 /*
  * Output a plain backspace, without erasing the previous char.
  */
-putbs()
+void putbs(void)
 {
 	tputs(sc_backspace, 1, putchr);
 }
 
-putchr(c)
-        int c;
+int putchr(int c)
 {
         if (ob >= &obuf[sizeof(obuf)])
                 flush();
         *ob++ = c;
+	return (c);
 }
 
-putstr(s)
-        register char *s;
+void putstr(register char *s)
 {
         while (*s != '\0')
                 putchr(*s++);
 }
 
 
-flush()
+void flush(void)
 {
         register int n;
 
@@ -676,10 +673,7 @@
         return ((unsigned char)c);
 }
 
-iread(fd, buf, len)
-        int fd;
-        char *buf;
-        int len;
+int iread(int fd, char *buf, int len)
 {
         register int n;
 
