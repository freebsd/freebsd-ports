--- ./QW/client/cl_main.c.orig	Sat Mar 11 16:45:47 2006
+++ ./QW/client/cl_main.c	Sun May 14 16:20:57 2006
@@ -45,6 +45,7 @@
 #include "winsock.h"
 #include "winquake.h"
 #else
+#include <sys/types.h>
 #include <netinet/in.h>
 #endif
 
@@ -863,6 +864,7 @@
 	    Con_Printf("Command packet from remote host.  Ignored.\n");
 	    return;
 	}
+
 #ifdef _WIN32
 	ShowWindow(mainwindow, SW_RESTORE);
 	SetForegroundWindow(mainwindow);
