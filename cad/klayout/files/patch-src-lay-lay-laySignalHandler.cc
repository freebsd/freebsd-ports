--- src/lay/lay/laySignalHandler.cc.orig	2019-02-23 17:34:47 UTC
+++ src/lay/lay/laySignalHandler.cc
@@ -450,7 +450,7 @@ void install_signal_handlers ()
   act.sa_sigaction = signal_handler;
   sigemptyset (&act.sa_mask);
   act.sa_flags = SA_SIGINFO;
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DrafonFly__)
   act.sa_restorer = 0;
 #endif
 
