--- monotone.cc.orig	Sun Sep 17 11:56:38 2006
+++ monotone.cc	Sat Sep 23 18:42:05 2006
@@ -188,8 +188,10 @@
   if (!init)
     {
       setlocale(LC_ALL, "");
+#ifdef ENABLE_NLS
       bindtextdomain(PACKAGE, LOCALEDIR);
       textdomain(PACKAGE);
+#endif
       init = 1;
     }
 }
