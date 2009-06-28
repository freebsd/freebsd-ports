--- libs/std/process.c.orig	2009-06-19 00:08:00.000000000 +0900
+++ libs/std/process.c	2009-06-19 00:08:06.000000000 +0900
@@ -23,7 +23,7 @@
 #	include <unistd.h>
 #	include <errno.h>
 #	ifndef NEKO_MAC
-#		include <wait.h>
+#		include <sys/wait.h>
 #	endif
 #endif
 
