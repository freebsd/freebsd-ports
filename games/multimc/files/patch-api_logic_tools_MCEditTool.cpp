--- api/logic/tools/MCEditTool.cpp.orig	2019-03-09 18:30:20 UTC
+++ api/logic/tools/MCEditTool.cpp
@@ -52,7 +52,7 @@ QString MCEditTool::getProgramPath()
 #else
     const QString mceditPath = path();
     QDir mceditDir(mceditPath);
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     if (mceditDir.exists("mcedit.sh"))
     {
         return mceditDir.absoluteFilePath("mcedit.sh");
