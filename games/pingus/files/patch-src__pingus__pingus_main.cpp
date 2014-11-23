--- src/pingus/pingus_main.cpp.orig	2011-12-25 01:46:47.000000000 +0400
+++ src/pingus/pingus_main.cpp	2014-10-17 23:57:58.000000000 +0400
@@ -465,7 +465,7 @@
 void
 PingusMain::print_greeting_message()
 {
-  std::string greeting = "Welcome to Pingus "VERSION;
+  std::string greeting = "Welcome to Pingus " VERSION;
   greeting += "!";
   std::cout <<  greeting << std::endl;
   for (unsigned int i = 0; i < greeting.length(); ++i)
