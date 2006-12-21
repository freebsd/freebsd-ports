--- ./sys_linux.c.orig	Mon Mar 20 10:51:28 2006
+++ ./sys_linux.c	Tue Aug 29 20:59:12 2006
@@ -35,7 +35,6 @@
 #include <ctype.h>
 #include <sys/wait.h>
 #include <sys/mman.h>
-#include <linux/rtc.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #include <sched.h>
@@ -256,6 +255,7 @@
 		if (COM_CheckParm("-nostdout"))
 			sys_nostdout.value = 1;
 
+#if 0
 		/* also check for -rtctimer before Host_Init is called */
 		if (COM_CheckParm("-rtctimer")) {
 		    int retval;
@@ -292,6 +292,7 @@
 
 		    Com_Printf("RTC Timer Enabled.\n");
 		}
+#endif
 		    
 		#if id386
 			Sys_SetFPCW();
