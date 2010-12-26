--- lib/exceptionhandler/exceptionhandler.c.orig	2010-11-28 22:39:00.000000000 +0300
+++ lib/exceptionhandler/exceptionhandler.c	2010-12-22 20:00:57.000000000 +0300
@@ -122,10 +122,6 @@
 # include <sys/stat.h>
 # include <sys/wait.h>
 # include <sys/utsname.h>
-# include <sys/prctl.h>
-#ifndef PR_SET_PTRACER
-# define PR_SET_PTRACER 0x59616d61  // prctl will ignore unknown options
-#endif
 
 // GNU extension for backtrace():
 # if defined(__GLIBC__)
@@ -492,9 +488,6 @@
 	// Check to see if we're the parent
 	if (pid != 0)
 	{
-		// Allow tracing the process, some hardened kernel configurations disallow this.
-		prctl(PR_SET_PTRACER, pid, 0, 0, 0);
-
 		// Return the write end of the pipe
 		*gdbWritePipe = gdbPipe[1];
 
