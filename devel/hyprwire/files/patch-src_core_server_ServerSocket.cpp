--- src/core/server/ServerSocket.cpp.orig	2025-11-23 08:06:13 UTC
+++ src/core/server/ServerSocket.cpp
@@ -9,6 +9,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <netinet/in.h>
+#include <unistd.h>
 
 #include <filesystem>
 #include <hyprutils/utils/ScopeGuard.hpp>
