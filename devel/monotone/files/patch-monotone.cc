--- monotone.cc.orig	Fri Dec 31 03:16:53 2004
+++ monotone.cc	Wed Jan 26 22:20:17 2005
@@ -140,8 +140,10 @@
 
   setlocale(LC_CTYPE, "");
   setlocale(LC_MESSAGES, "");
+#ifdef ENABLE_NLS
   bindtextdomain(PACKAGE, LOCALEDIR);
   textdomain(PACKAGE);
+#endif
 
   L(F("set locale: LC_CTYPE=%s, LC_MESSAGES=%s\n")
     % (setlocale(LC_CTYPE, NULL) == NULL ? "n/a" : setlocale(LC_CTYPE, NULL))
