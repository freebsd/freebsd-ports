--- HelpWindow.cpp.orig	Thu Oct  2 04:40:40 2003
+++ HelpWindow.cpp	Fri Aug 20 23:49:10 2004
@@ -36,7 +36,15 @@
   QString vipecHome = QString(getenv("VIPECHOME"));
   if ( vipecHome.isEmpty() )
     {
+#ifdef VIPECHOME
+      vipecHome = QString(VIPECHOME);
+      if (vipecHome.isEmpty())
+        {
+	  vipecHome = dir.absPath();
+        }
+#else
       vipecHome = dir.absPath();
+#endif
     }
   home_ = vipecHome + "/help/index.html";
   const QStringList currentDir(".");
