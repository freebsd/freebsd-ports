--- textio/textioInt.h.orig	Tue Dec  9 16:41:17 2003
+++ textio/textioInt.h	Tue Dec  9 16:41:29 2003
@@ -48,7 +48,7 @@
 #define TX_LONG_CMD2	';'	/* Alternate way of invoking a long command. */
 
 /* all of the state associated with a tty terminal */
-#if !defined(SYSV) && !defined(CYGWIN)
+#if !defined(__FreeBSD__) && !defined(SYSV) && !defined(CYGWIN)
 typedef struct {
     struct sgttyb tx_i_sgtty;
     struct tchars tx_i_tchars;
@@ -56,4 +56,4 @@
 #endif SYSV
 
 extern int TxGetInputEvent();
-extern void txFprintfBasic();
+extern void txFprintfBasic(FILE *f, char *fmt, ... );
