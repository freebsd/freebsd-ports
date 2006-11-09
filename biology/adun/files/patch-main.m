--- Kernel/main.m.orig	Mon Aug  7 12:17:30 2006
+++ Kernel/main.m	Sun Nov  5 13:27:26 2006
@@ -3,7 +3,9 @@
 #include <stdio.h>
 #include <float.h>
 #include <fenv.h>
+#ifndef __FreeBSD__
 #include <mcheck.h>
+#endif
 #include "AdunKernel/AdunKernel.h"
 
 /** \mainpage
@@ -250,8 +252,10 @@
 
 	if([[NSUserDefaults standardUserDefaults] boolForKey: @"TraceMemory"] == YES)
 	{
+#ifndef __FreeBSD__
 		mtrace();
 		mcheck(NULL);
+#endif
 	}
 
 	logFile = [[NSUserDefaults standardUserDefaults] stringForKey: @"LogFile"];
