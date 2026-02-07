--- src/view/telnetcon.cpp.orig	2016-02-16 12:31:46 UTC
+++ src/view/telnetcon.cpp
@@ -77,7 +77,6 @@
 #ifdef USING_LINUX
 #include <pty.h>
 #endif
-#include <utmp.h>
 
 #include <signal.h>
 #include <sys/wait.h>
