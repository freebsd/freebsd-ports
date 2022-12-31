--- src/cpp/shared_core/system/PosixSystem.cpp.orig	2022-12-30 20:20:59 UTC
+++ src/cpp/shared_core/system/PosixSystem.cpp
@@ -27,7 +27,11 @@
 #include <ifaddrs.h>
 #include <memory.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <pwd.h>
+#include <sys/socket.h>
+#include <sys/types.h>
+
 
 #ifdef __linux__
 #include <sys/prctl.h>
