$FreeBSD$

--- ../src/solaris/hpi/native_threads/src/threads_md.c	21 Nov 2001 04:02:04 -0000	1.4
+++ ../src/solaris/hpi/native_threads/src/threads_md.c	24 Feb 2003 03:17:30 -0000
@@ -23,6 +23,7 @@
 #include <setjmp.h>
 #include <signal.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/signal.h>
 #include <sys/resource.h>
 #ifdef __FreeBSD__
