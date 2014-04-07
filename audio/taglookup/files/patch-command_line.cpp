--- ./command_line.cpp.orig	2007-10-01 21:09:46.000000000 +0200
+++ ./command_line.cpp	2014-04-07 10:14:49.462722923 +0200
@@ -105,7 +105,7 @@
     
     bool CommandLineArgumentsParser::parsePort()
     {
-        int port = (int)std::strtol(ct_.c_str(), (char**)NULL, 10);
+        int port = (int)strtol(ct_.c_str(), (char**)NULL, 10);
         
         if(port > 32767 || port <= 0)
         {
