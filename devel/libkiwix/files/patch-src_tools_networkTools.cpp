Has been upstreamed via https://github.com/kiwix/libkiwix/pull/1173 and will be
included in next release (14.1.0), so remove this patch at next update.

--- src/tools/networkTools.cpp.orig	2024-10-09 17:18:52 UTC
+++ src/tools/networkTools.cpp
@@ -42,6 +42,7 @@
 #include <arpa/inet.h>
 #include <ifaddrs.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <net/if.h>
 #include <netdb.h>
 #endif
