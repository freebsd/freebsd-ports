--- ./sys_linux.c.orig	Thu Jul 12 20:11:59 2007
+++ ./sys_linux.c	Thu Jul 12 20:12:00 2007
@@ -36,7 +36,6 @@
 #include <ctype.h>
 #include <sys/wait.h>
 #include <sys/mman.h>
-#include <linux/rtc.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #include <sched.h>
@@ -257,6 +256,7 @@
 		if (COM_CheckParm("-nostdout"))
 			sys_nostdout.value = 1;
 
+#if 0
 		/* also check for -rtctimer before Host_Init is called */
 		if (COM_CheckParm("-rtctimer")) {
 		    int retval;
@@ -293,6 +293,7 @@
 
 		    Com_Printf("RTC Timer Enabled.\n");
 		}
+#endif
 		    
 		#ifdef id386
 			Sys_SetFPCW();
