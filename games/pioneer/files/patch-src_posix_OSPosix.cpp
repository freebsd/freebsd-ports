--- src/posix/OSPosix.cpp.orig	2014-08-28 18:02:26.000000000 +0400
+++ src/posix/OSPosix.cpp	2014-08-31 21:03:27.000000000 +0400
@@ -111,7 +111,7 @@
 	}
 
 	char infoString[2048];
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FREEBSD__)
 	snprintf(infoString, 2048, "System Name: %s\nHost Name: %s\nRelease(Kernel) Version: %s\nKernel Build Timestamp: %s\nMachine Arch: %s\n",
 		uts.sysname, uts.nodename, uts.release, uts.version, uts.machine);
 #else
