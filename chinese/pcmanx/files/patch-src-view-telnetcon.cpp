--- src/view/telnetcon.cpp.orig	2010-10-12 21:12:03.000000000 +0800
+++ src/view/telnetcon.cpp	2010-10-12 21:12:09.000000000 +0800
@@ -72,7 +72,6 @@
 #ifdef USING_LINUX
 #include <pty.h>
 #endif
-#include <utmp.h>
 
 #include <signal.h>
 #include <sys/wait.h>
