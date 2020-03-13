--- remoting/host/evaluate_capability.cc.orig	2019-12-12 12:39:55 UTC
+++ remoting/host/evaluate_capability.cc
@@ -50,7 +50,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
