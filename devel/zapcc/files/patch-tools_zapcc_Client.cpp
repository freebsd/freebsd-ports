--- tools/zapcc/Client.cpp.orig	2018-07-16 20:34:51 UTC
+++ tools/zapcc/Client.cpp
@@ -43,6 +43,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #endif
 #ifdef LLVM_ON_WIN32
 #include <windows.h>
