--- server/server.cpp.orig	2021-10-05 17:07:11 UTC
+++ server/server.cpp
@@ -103,11 +103,11 @@ Server::Server(int argc, char** argv)
       "ignore SANE network scanners",
       localonly },
     { "options-file",
-      "/etc/airsane/options.conf",
+      "%%PREFIX%%/etc/airsane/options.conf",
       "location of device options file",
       optionsfile },
     { "ignore-list",
-      "/etc/airsane/ignore.conf",
+      "%%PREFIX%%/etc/airsane/ignore.conf",
       "location of device ignore list",
       ignorelist },
     { "debug", "false", "log debug information to stderr", debug },
