--- mlcd/ParPort.cpp.orig	Sat May 24 08:03:20 2003
+++ mlcd/ParPort.cpp	Sat May 24 08:03:48 2003
@@ -926,9 +926,6 @@
 #elif defined(PAR_PLATFORM_FREEBSD)
 	#include <unistd.h>
 	#include <fcntl.h>
-    extern "C" {
-	#include <machine/cpufunc.h>
-    }
 #else
 	/* TODO: Handle these more gracefully! */
 	#error Undefined platform
