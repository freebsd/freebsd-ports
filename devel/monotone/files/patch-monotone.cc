--- monotone.cc.orig	Wed Jan  7 13:11:47 2004
+++ monotone.cc	Sun Mar 21 22:49:59 2004
@@ -129,8 +129,11 @@
 
   setlocale(LC_CTYPE, "");
   setlocale(LC_MESSAGES, "");
+
+#ifdef ENABLE_NLS
   bindtextdomain(PACKAGE, LOCALEDIR);
   textdomain(PACKAGE);
+#endif
 
   // decode all argv values into a UTF-8 array
 
