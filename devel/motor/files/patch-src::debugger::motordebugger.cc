--- src/debugger/motordebugger.cc.orig	Tue Oct 12 12:34:20 2004
+++ src/debugger/motordebugger.cc	Tue Oct 12 12:34:52 2004
@@ -9,6 +9,7 @@
 
 #include <strstream>
 #include <iostream>
+#include <memory>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/wait.h>
