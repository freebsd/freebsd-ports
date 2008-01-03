--- term.c.orig	2007-12-04 15:42:55.000000000 +0300
+++ term.c	2007-12-04 15:43:04.000000000 +0300
@@ -30,8 +30,8 @@
 #include <console.h>
 #endif
 
-#ifdef HAVE_TERMIO_H
-#include <termio.h>
+#if 1
+#include <termios.h>
 #else
 #ifdef HAVE_SGTTY_H
 #include <sgtty.h>
@@ -71,8 +71,8 @@
 char so_arr[40];
 char se_arr[40];
 
-#ifdef HAVE_TERMIO_H
-struct termio tty_cooked, tty_cbreak;
+#if 1
+struct termios tty_cooked, tty_cbreak;
 #else
 #ifdef HAVE_SGTTY_H
 struct sgttyb tty_cooked, tty_cbreak;
@@ -85,7 +85,7 @@
 
 char *termcap_ptr;
 
-int termcap_putter(char ch) {
+int termcap_putter(int ch) {
     *termcap_ptr++ = ch;
     return 0;
 }
@@ -125,8 +125,8 @@
 #endif /* WIN32 */
 #else
     if (interactive) {
-#ifdef HAVE_TERMIO_H
-	ioctl(0,TCGETA,(char *)(&tty_cooked));
+#if 1
+	tcgetattr(0, &tty_cooked);
 	tty_cbreak = tty_cooked;
 	tty_cbreak.c_cc[VMIN] = '\01';
 	tty_cbreak.c_cc[VTIME] = '\0';
@@ -181,8 +181,8 @@
 void charmode_on() {
 #ifdef unix
     if ((readstream == stdin) && interactive && !tty_charmode) {
-#ifdef HAVE_TERMIO_H
-	ioctl(0,TCSETA,(char *)(&tty_cbreak));
+#if 1
+	tcsetattr(0, TCSANOW, &tty_cbreak);
 #else /* !HAVE_TERMIO_H */
 	ioctl(0,TIOCSETP,(char *)(&tty_cbreak));
 #endif /* HAVE_TERMIO_H */
@@ -197,8 +197,8 @@
 void charmode_off() {
 #ifdef unix
     if (tty_charmode) {
-#ifdef HAVE_TERMIO_H
-	ioctl(0,TCSETA,(char *)(&tty_cooked));
+#if 1
+	tcsetattr(0, TCSANOW, &tty_cooked);
 #else /* !HAVE_TERMIO_H */
 	ioctl(0,TIOCSETP,(char *)(&tty_cooked));
 #endif /* HAVE_TERMIO_H */
