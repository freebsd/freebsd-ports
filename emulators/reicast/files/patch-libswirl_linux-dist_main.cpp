--- libswirl/linux-dist/main.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/linux-dist/main.cpp
@@ -7,7 +7,7 @@
 #include "types.h"
 #include "cfg/cfg.h"
 
-#if HOST_OS==OS_LINUX
+#if HOST_OS==OS_LINUX || HOST_OS==OS_FREEBSD
 #include <poll.h>
 #include <termios.h>
 //#include <curses.h>
@@ -22,7 +22,9 @@
 #include "hw/sh4/dyna/blockmanager.h"
 #include "hw/maple/maple_cfg.h"
 #include <unistd.h>
+#if HOST_OS==OS_LINUX
 #include <pty.h>
+#endif
 
 #include "libswirl.h"
 #include "hw/pvr/Renderer_if.h"
@@ -539,6 +541,7 @@ int main(int argc, wchar* argv[])
  
 int get_mic_data(u8* buffer) { return 0; }
 
+#if HOST_OS == OS_LINUX
 void os_DebugBreak()
 {
 	#if !defined(TARGET_EMSCRIPTEN)
@@ -548,6 +551,7 @@ void os_DebugBreak()
 		exit(-1);
 	#endif
 }
+#endif
 
 
 
