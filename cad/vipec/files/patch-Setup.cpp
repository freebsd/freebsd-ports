--- Setup.cpp.orig	Fri Oct  3 09:31:11 2003
+++ Setup.cpp	Fri Aug 20 23:49:30 2004
@@ -163,8 +163,17 @@
   vipecHome_ = QString(getenv("VIPECHOME"));
   if ( vipecHome_.isEmpty() )
     {
-      vipecHome_ = dir.absPath();
-      Logger::warning("VIPECHOME not set, assuming " + vipecHome_);
+#ifdef VIPECHOME
+      vipecHome_ = QString(VIPECHOME);
+      if (vipecHome_.isEmpty())
+        {
+	  vipecHome_ = dir.absPath();
+	  Logger::warning("VIPECHOME not set, assuming " + vipecHome_);
+        }
+#else
+	vipecHome_ = dir.absPath();
+	Logger::warning("VIPECHOME not set, assuming " + vipecHome_);
+#endif
     }
   helpFilename_ = vipecHome_ + "/help/index.html";
   configFilename_ = vipecHome_ + "/vipec.cfg";
