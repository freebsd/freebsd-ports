--- command_line.cpp.orig	2007-10-01 19:09:46 UTC
+++ command_line.cpp
@@ -105,7 +105,7 @@ namespace TagLookup
     
     bool CommandLineArgumentsParser::parsePort()
     {
-        int port = (int)std::strtol(ct_.c_str(), (char**)NULL, 10);
+        int port = (int)strtol(ct_.c_str(), (char**)NULL, 10);
         
         if(port > 32767 || port <= 0)
         {
