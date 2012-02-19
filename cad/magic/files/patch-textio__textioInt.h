--- textio/textioInt.h.orig	2006-04-11 07:03:13.000000000 +0900
+++ textio/textioInt.h	2012-01-17 02:37:35.000000000 +0900
@@ -41,7 +41,7 @@
 #define TX_CMD_PROMPT	":"
 
 /* all of the state associated with a tty terminal */
-#if !defined(SYSV) && !defined(CYGWIN)
+#if !defined(SYSV) && !defined(CYGWIN) && !defined(__FreeBSD__)
 typedef struct {
     struct sgttyb tx_i_sgtty;
     struct tchars tx_i_tchars;
