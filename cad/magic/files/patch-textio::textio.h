--- textio/textio.h.orig	Tue Dec  9 16:44:37 2003
+++ textio/textio.h	Tue Dec  9 16:56:52 2003
@@ -29,10 +29,10 @@
 #endif
 
 /* printing procedures */
-extern void TxPrintf();
+/* extern void TxPrintf(); */
 extern bool TxPrintOn();  	/* enables TxPrintf output */
 extern bool TxPrintOff();	/* disables TxPrintf output */
-extern void TxError();
+/* extern void TxError(); */
 extern void TxFlush();
 extern void TxVisChar();
 extern void TxUseMore();
