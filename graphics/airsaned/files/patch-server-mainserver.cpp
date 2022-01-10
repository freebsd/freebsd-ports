--- server/mainserver.cpp.orig	2021-02-01 18:41:51 UTC
+++ server/mainserver.cpp
@@ -83,11 +83,11 @@ MainServer::MainServer(int argc, char** argv)
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
     { "random-uuids",
