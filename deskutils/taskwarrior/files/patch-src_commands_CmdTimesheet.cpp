--- src/commands/CmdTimesheet.cpp.orig	2015-10-21 20:50:42 UTC
+++ src/commands/CmdTimesheet.cpp
@@ -75,7 +75,7 @@ int CmdTimesheet::execute (std::string& 
 
   // Roll back to midnight.
   start = ISO8601d (start.month (), start.day (), start.year ());
-  ISO8601d end = start + (7 * 86400);
+  ISO8601d end = start + (time_t)(7 * 86400);
 
   // Determine how many reports to run.
   int quantity = 1;
