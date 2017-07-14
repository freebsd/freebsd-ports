--- src/pingus/pingus_main.cpp.orig	2011-12-24 21:46:47 UTC
+++ src/pingus/pingus_main.cpp
@@ -465,7 +465,7 @@ PingusMain::init_path_finder()
 void
 PingusMain::print_greeting_message()
 {
-  std::string greeting = "Welcome to Pingus "VERSION;
+  std::string greeting = "Welcome to Pingus " VERSION;
   greeting += "!";
   std::cout <<  greeting << std::endl;
   for (unsigned int i = 0; i < greeting.length(); ++i)
