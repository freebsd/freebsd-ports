--- src/arch/ArchHooks/ArchHooks_Unix.cpp.orig	2012-08-06 14:23:36.000000000 +0900
+++ src/arch/ArchHooks/ArchHooks_Unix.cpp	2012-09-24 00:09:58.000000000 +0900
@@ -12,6 +12,7 @@
 #include "archutils/Unix/AssertionHandler.h"
 #include <unistd.h>
 #include <sys/time.h>
+#include <sys/wait.h>
 
 #if defined(CRASH_HANDLER)
 #include "archutils/Unix/CrashHandler.h"
