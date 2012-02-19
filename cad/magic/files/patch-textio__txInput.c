--- textio/txInput.c.orig	2012-01-17 02:40:11.000000000 +0900
+++ textio/txInput.c	2012-01-17 02:45:26.000000000 +0900
@@ -1204,14 +1204,14 @@
  * ----------------------------------------------------------------------------
  */
 
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
 
 void
 txGetTermState(buf)
-    struct termio *buf;
+    struct termios *buf;
 
 {
-    ioctl( fileno( stdin ), TCGETA, buf);
+    ioctl( fileno( stdin ), TIOCGETA, buf);
 }
 
 #else
@@ -1244,14 +1244,14 @@
 
 void
 txSetTermState(buf)
-#if defined(SYSV) || defined(CYGWIN)
-    struct termio *buf;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    struct termios *buf;
 #else
     txTermState *buf;
 #endif /* SYSV */
 {
-#if defined(SYSV) || defined(CYGWIN)
-    ioctl( fileno(stdin), TCSETAF, buf );
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    ioctl( fileno(stdin), TIOCSETAF, buf );
 #else
     /* set the current terminal characteristics */
     (void) ioctl(fileno(stdin), TIOCSETN, (char *) &(buf->tx_i_sgtty) );
@@ -1279,13 +1279,13 @@
 
 void
 txInitTermRec(buf)
-#if defined(SYSV) || defined(CYGWIN)
-    struct termio *buf;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    struct termios *buf;
 #else
     txTermState *buf;
 #endif /* SYSV */
 {
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
     buf->c_lflag = ISIG;    /* raw: no echo and no processing, allow signals */
     buf->c_cc[ VMIN ] = 1;
     buf->c_cc[ VTIME ] = 0;
@@ -1300,8 +1300,8 @@
 
 
 
-#if defined(SYSV) || defined(CYGWIN)
-struct termio closeTermState;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+struct termios closeTermState;
 #else
 static txTermState closeTermState;
 #endif /* SYSV */
@@ -1327,8 +1327,8 @@
 void
 txSaveTerm()
 {
-#if defined(SYSV) || defined(CYGWIN)
-    ioctl( fileno( stdin ), TCGETA, &closeTermState);
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    ioctl( fileno( stdin ), TIOCGETA, &closeTermState);
     txEraseChar = closeTermState.c_cc[VERASE];
     txKillChar =  closeTermState.c_cc[VKILL];
     TxEOFChar = closeTermState.c_cc[VEOF];
@@ -1368,8 +1368,8 @@
 void
 TxSetTerminal()
 {
-#if defined(SYSV) || defined(CYGWIN)
-    struct termio buf;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    struct termios buf;
 #else
     txTermState buf;
 #endif /* SYSV */
