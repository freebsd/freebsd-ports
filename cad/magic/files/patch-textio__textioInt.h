--- textio/textioInt.h.orig	2020-05-24 07:00:08 UTC
+++ textio/textioInt.h
@@ -41,7 +41,7 @@ typedef struct {
 #define TX_CMD_PROMPT	":"
 
 /* all of the state associated with a tty terminal */
-#if !defined(SYSV) && !defined(CYGWIN)
+#if !defined(SYSV) && !defined(CYGWIN) && !defined(__FreeBSD__)
 typedef struct {
     struct sgttyb tx_i_sgtty;
     struct tchars tx_i_tchars;
