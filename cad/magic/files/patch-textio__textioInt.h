--- textio/textioInt.h.orig	2023-07-12 06:00:01 UTC
+++ textio/textioInt.h
@@ -41,7 +41,7 @@ typedef struct {
 #define TX_CMD_PROMPT	":"
 
 /* all of the state associated with a tty terminal */
-#if !defined(SYSV) && !defined(CYGWIN) && !defined(__OpenBSD__) && !defined(EMSCRIPTEN)
+#if !defined(SYSV) && !defined(CYGWIN) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(EMSCRIPTEN)
 typedef struct {
     struct sgttyb tx_i_sgtty;
     struct tchars tx_i_tchars;
