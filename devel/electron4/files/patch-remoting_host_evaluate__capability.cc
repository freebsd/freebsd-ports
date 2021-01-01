--- remoting/host/evaluate_capability.cc.orig	2019-03-15 06:37:31 UTC
+++ remoting/host/evaluate_capability.cc
@@ -49,7 +49,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
