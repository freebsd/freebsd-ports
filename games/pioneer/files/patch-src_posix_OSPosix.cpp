--- src/posix/OSPosix.cpp.orig	2015-06-07 21:44:10 UTC
+++ src/posix/OSPosix.cpp
@@ -107,7 +107,7 @@
 	}
 
 	char infoString[2048];
-#if defined(__APPLE__)
+#if !defined(__linux__)
 	snprintf(infoString, 2048, "System Name: %s\nHost Name: %s\nRelease(Kernel) Version: %s\nKernel Build Timestamp: %s\nMachine Arch: %s\n",
 		uts.sysname, uts.nodename, uts.release, uts.version, uts.machine);
 #else
