--- src/ServerBrowser/Main.cpp.orig	Mon May 31 21:24:01 2004
+++ src/ServerBrowser/Main.cpp	Mon May 31 21:24:44 2004
@@ -16,7 +16,7 @@
     srand(time(0));
 
     BrowserConfig* config = new BrowserConfig;
-    config->ircserver = "irc.freenode.net";
+    config->ircserver = "irc.quakenet.org";
     config->connect_timeout = 20;
     config->query_timeout = 20;
 
