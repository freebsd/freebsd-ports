--- src/core/client/ClientSocket.cpp.orig	2025-11-23 08:07:11 UTC
+++ src/core/client/ClientSocket.cpp
@@ -18,6 +18,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <netinet/in.h>
+#include <unistd.h>
 
 #include <filesystem>
 #include <hyprutils/utils/ScopeGuard.hpp>
