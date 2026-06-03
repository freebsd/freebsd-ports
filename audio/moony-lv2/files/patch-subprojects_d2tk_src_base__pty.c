--- subprojects/d2tk/src/base_pty.c.orig	2021-07-15 21:37:59 UTC
+++ subprojects/d2tk/src/base_pty.c
@@ -19,12 +19,15 @@
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
+#include <stdlib.h>
 #include <fcntl.h>
+#include <unistd.h>
 #include <vterm.h>
-#include <pty.h>
-#include <utmp.h>
+#include <libutil.h>
+#include <termios.h>
 #include <sched.h>
 #include <limits.h>
+#include <sys/ioctl.h>
 #include <sys/wait.h>
 #include <sys/mman.h>
 #include <pthread.h>
@@ -32,6 +35,8 @@
 
 #include "base_internal.h"
 
+extern char **environ;
+
 #define DEFAULT_FG 0xddddddff
 #define DEFAULT_BG 0x222222ff
 
@@ -183,7 +188,7 @@
 		return 0;
 	}
 
-	pthread_join(vpty->kid, NULL);
+	pthread_join((pthread_t)vpty->kid, NULL);
 
 #if D2TK_DEBUG == 1
 				fprintf(stderr, "[%s] child with pid %ld has exited\n",
@@ -432,7 +437,7 @@
 
 	*amaster = thread_data_master;
 
-	return thread;
+	return (ptrdiff_t)thread;
 }
 
 static ptrdiff_t
@@ -587,7 +592,7 @@
 		// send CTRL-C
 		vterm_keyboard_unichar(vpty->vterm, 0x3, VTERM_MOD_NONE);
 
-		pthread_join(vpty->kid, NULL);
+		pthread_join((pthread_t)vpty->kid, NULL);
 
 #if D2TK_DEBUG == 1
 				fprintf(stderr, "[%s] child with pid %ld has exited\n",
