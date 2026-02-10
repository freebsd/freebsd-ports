--- tests/Fork.cpp.orig	2026-02-10 08:21:03 UTC
+++ tests/Fork.cpp
@@ -3,6 +3,7 @@
 #include <sys/poll.h>
 #include <sys/signal.h>
 #include <sys/socket.h>
+#include <unistd.h>
 
 #include "generated/test_protocol_v1-server.hpp"
 #include "generated/test_protocol_v1-client.hpp"
