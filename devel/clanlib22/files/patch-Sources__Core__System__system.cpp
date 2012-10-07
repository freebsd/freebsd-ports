--- ./Sources/Core/System/system.cpp.orig	2012-09-25 07:46:49.000000000 -0400
+++ ./Sources/Core/System/system.cpp	2012-09-25 07:57:19.000000000 -0400
@@ -1,3 +1,4 @@
+
 /*
 **  ClanLib SDK
 **  Copyright (c) 1997-2011 The ClanLib Team
@@ -44,7 +45,7 @@
 #include <sys/sysctl.h>
 #endif
 
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__FreeBSD__))
 #include <execinfo.h>
 #endif
 #include <cxxabi.h>
@@ -128,7 +129,7 @@
 		*out_hash = 0;
 	return capturedFrames;
 
-#elif !defined(__APPLE__)
+#elif !(defined(__APPLE__) || defined(__FreeBSD__))
 	// Ensure the output is cleared
 	memset(out_frames, 0, (sizeof(void *)) * max_frames);
 
@@ -188,7 +189,7 @@
 	SymCleanup(GetCurrentProcess());
 	return backtrace_text;
 
-#elif !defined(__APPLE__)
+#elif !(defined(__APPLE__) || defined(__FreeBSD__))
 
 	char **strings;
  	strings = backtrace_symbols(frames, num_frames);
