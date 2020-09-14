--- tftp/tftp.c.orig	2011-12-11 22:13:52 UTC
+++ tftp/tftp.c
@@ -48,7 +48,7 @@ extern int maxtimeout;
 #define PKTSIZE    SEGSIZE+4
 char ackbuf[PKTSIZE];
 int timeout;
-sigjmp_buf toplevel;
+extern sigjmp_buf toplevel;
 sigjmp_buf timeoutbuf;
 
 static void nak(int, const char *);
