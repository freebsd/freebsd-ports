--- textio/textioInt.h.orig	Tue Dec  9 16:41:17 2003
+++ textio/textioInt.h	Tue Dec  9 16:41:29 2003
@@ -53,7 +53,7 @@
     struct sgttyb tx_i_sgtty;
     struct tchars tx_i_tchars;
 } txTermState;
-#endif SYSV
+#endif
 
 extern int TxGetInputEvent();
-extern void txFprintfBasic();
+extern void txFprintfBasic(FILE *f, char *fmt, ... );
