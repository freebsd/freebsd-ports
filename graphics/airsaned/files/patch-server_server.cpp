--- server/server.cpp.orig	2021-10-19 16:15:25 UTC
+++ server/server.cpp
@@ -104,7 +104,7 @@ Server::Server(int argc, char** argv)
       localonly },
     { "options-file",
 #ifdef __FreeBSD__
-      "/usr/local/etc/airsane/options.conf",
+      "%%PREFIX%%/etc/airsane/options.conf",
 #else
       "/etc/airsane/options.conf",
 #endif
@@ -112,7 +112,7 @@ Server::Server(int argc, char** argv)
       optionsfile },
     { "ignore-list",
 #ifdef __FreeBSD__
-      "/usr/local/etc/airsane/ignore.conf",
+      "%%PREFIX%%/etc/airsane/ignore.conf",
 #else
       "/etc/airsane/ignore.conf",
 #endif
