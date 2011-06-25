--- src/include/fteext.h.orig	2011-06-24 16:19:49.000000000 +0000
+++ src/include/fteext.h	2011-06-24 16:21:21.000000000 +0000
@@ -419,7 +419,7 @@
 extern SIGNAL_TYPE sigbus();
 extern SIGNAL_TYPE sigsegv();
 extern SIGNAL_TYPE sig_sys();
-extern void main();
+extern int main();
 
 /* spiceif.c & nutmegif.c */
 
