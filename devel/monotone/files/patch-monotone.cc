--- monotone.cc.orig    Fri Sep 30 11:50:05 2005
+++ monotone.cc Fri Oct 14 11:31:14 2005
@@ -238,8 +238,10 @@
   // go-go gadget i18n
 
   setlocale(LC_ALL, "");
+#ifdef ENABLE_NLS
   bindtextdomain(PACKAGE, LOCALEDIR);
   textdomain(PACKAGE);
+#endif
 
 
   // we want to catch any early informative_failures due to charset
