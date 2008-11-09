--- src/campaign_server/campaign_server.cpp.orig	2008-11-02 17:51:05.000000000 +0100
+++ src/campaign_server/campaign_server.cpp	2008-11-02 17:52:07.000000000 +0100
@@ -46,6 +46,7 @@
 // work on Windows not sure which other platforms have a problem with it.
 #if !(defined(_WIN32))
 #include <errno.h>
+#include <signal.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
