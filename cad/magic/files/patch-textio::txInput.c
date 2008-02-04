--- textio/txInput.c	2001-09-21 17:15:56.000000000 +0200
+++ textio/txInput.c	2008-02-04 19:26:44.000000000 +0100
@@ -1027,7 +1027,16 @@
  * ----------------------------------------------------------------------------
  */
 
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+void
+txGetTermState(buf)
+    struct termios *buf;
+
+{
+    tcgetattr( fileno( stdin ), buf);
+}
+
+#elif defined(SYSV) || defined(CYGWIN)
 void
 txGetTermState(buf)
     struct termio *buf;
@@ -1066,13 +1075,17 @@
 
 void
 txSetTermState(buf)
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+    struct termios *buf;
+#elif defined(SYSV) || defined(CYGWIN)
     struct termio *buf;
 #else
     txTermState *buf;
 #endif SYSV
 {
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+    tcsetattr( fileno(stdin), TCSAFLUSH, buf );
+#elif defined(SYSV) || defined(CYGWIN)
     ioctl( fileno(stdin), TCSETAF, buf );
 #else
     /* set the current terminal characteristics */
@@ -1100,13 +1113,15 @@
 
 void
 txInitTermRec(buf)
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+    struct termios *buf;
+#elif defined(SYSV) || defined(CYGWIN)
     struct termio *buf;
 #else
     txTermState *buf;
 #endif SYSV
 {
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(__FreeBSD__) || defined(SYSV) || defined(CYGWIN)
     buf->c_lflag = ISIG;    /* raw: no echo and no processing, allow signals */
     buf->c_cc[ VMIN ] = 1;
     buf->c_cc[ VTIME ] = 0;
@@ -1124,7 +1139,9 @@
 
 
 
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+struct termios closeTermState;
+#elif defined(SYSV) || defined(CYGWIN)
 struct termio closeTermState;
 #else
 static txTermState closeTermState;
@@ -1151,7 +1168,14 @@
 void
 txSaveTerm()
 {
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+    tcgetattr( fileno( stdin ), &closeTermState);
+    txEraseChar = closeTermState.c_cc[VERASE];
+    txKillChar =  closeTermState.c_cc[VKILL];
+    TxEOFChar = closeTermState.c_cc[VEOF];
+    TxInterruptChar = closeTermState.c_cc[VINTR];
+    haveCloseState = TRUE;
+#elif defined(SYSV) || defined(CYGWIN)
     ioctl( fileno( stdin ), TCGETA, &closeTermState);
     txEraseChar = closeTermState.c_cc[VERASE];
     txKillChar =  closeTermState.c_cc[VKILL];
@@ -1192,7 +1216,9 @@
 void
 TxSetTerminal()
 {
-#if defined(SYSV) || defined(CYGWIN)
+#ifdef __FreeBSD__
+    struct termios buf;
+#elif defined(SYSV) || defined(CYGWIN)
     struct termio buf;
 #else
     txTermState buf;
