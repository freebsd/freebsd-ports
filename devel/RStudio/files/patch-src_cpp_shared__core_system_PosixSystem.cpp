- Add sys/types.h include required on FreeBSD

--- src/cpp/shared_core/system/PosixSystem.cpp.orig	2025-01-31 18:17:58 UTC
+++ src/cpp/shared_core/system/PosixSystem.cpp
@@ -31,6 +31,7 @@
 #include <netinet/in.h>
 #include <pwd.h>
 #include <sys/socket.h>
+#include <sys/types.h>
 
 #ifdef __linux__
 #include <sys/prctl.h>
