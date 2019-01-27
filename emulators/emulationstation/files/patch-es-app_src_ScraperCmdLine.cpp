Use POSIX sleep funtion, instead of Windows

--- es-app/src/ScraperCmdLine.cpp.orig	2018-08-11 01:17:21 UTC
+++ es-app/src/ScraperCmdLine.cpp
@@ -5,17 +5,13 @@
 #include "SystemData.h"
 #include <iostream>
 #include <signal.h>
-#if defined(__linux__)
 #include <unistd.h>
-#elif defined(WIN32)
-#include <Windows.h>
-#endif
 
 std::ostream& out = std::cout;
 
 void handle_interrupt_signal(int p)
 {
-	sleep(50);
+	usleep(50);
 
 	LOG(LogInfo) << "Interrupt received during scrape...";
 
