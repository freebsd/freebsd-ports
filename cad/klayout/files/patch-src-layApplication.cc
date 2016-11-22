--- src/layApplication.cc.orig	2016-06-19 16:35:29 UTC
+++ src/layApplication.cc
@@ -20,6 +20,7 @@
 
 */
 
+#include <sys/param.h>
 
 #include "layApplication.h"
 #include "layConfig.h"
@@ -74,6 +75,7 @@
 #include <memory>
 #include <algorithm>
 #include <signal.h>
+#include <unistd.h>
 
 namespace lay
 {
@@ -351,7 +353,7 @@ static void install_signal_handlers ()
   act.sa_sigaction = signal_handler;
   sigemptyset (&act.sa_mask);
   act.sa_flags = SA_SIGINFO;
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
   act.sa_restorer = 0;
 #endif
 
