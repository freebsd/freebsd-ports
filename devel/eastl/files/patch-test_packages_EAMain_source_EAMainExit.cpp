--- test/packages/EAMain/source/EAMainExit.cpp.orig	2024-09-01 08:01:04 UTC
+++ test/packages/EAMain/source/EAMainExit.cpp
@@ -15,7 +15,10 @@
 
 #if defined(EA_PLATFORM_SONY) || defined(EA_PLATFORM_ANDROID)
     // All of these platforms require complex handling of exceptions and signals. No apparent solution yet.
-#elif defined(EA_PLATFORM_LINUX)
+#elif defined(EA_PLATFORM_LINUX) || defined(EA_PLATFORM_FREEBSD)
+#if defined(EA_PLATFORM_FREEBSD)
+    #include <signal.h>
+#endif
     #include <sys/signal.h>
 #elif defined(EA_PLATFORM_APPLE) || defined(EA_PLATFORM_WINDOWS) || defined(EA_PLATFORM_XBOXONE) || defined(EA_PLATFORM_CAPILANO) || defined(CS_UNDEFINED_STRING)
     #include <csignal>
@@ -98,7 +101,7 @@
             std::signal(SIGHUP, HandleSignal);
             std::signal(SIGBUS, HandleSignal);
         }
-#elif defined(EA_PLATFORM_LINUX)
+#elif defined(EA_PLATFORM_LINUX) || defined(EA_PLATFORM_FREEBSD)
         int SignalToExitCode(int signal) {
             switch(signal)
             {
