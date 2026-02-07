--- ./code/qcommon/common.c.orig	Wed May 31 18:55:11 2006
+++ ./code/qcommon/common.c	Wed May 31 18:55:13 2006
@@ -24,15 +24,8 @@
 #include "../game/q_shared.h"
 #include "qcommon.h"
 #include <setjmp.h>
-#ifdef __linux__
-#include <netinet/in.h>
-#else
-#if defined(MACOS_X)
+#include <sys/types.h>
 #include <netinet/in.h>
-#else
-#include <winsock.h>
-#endif
-#endif
 
 int demo_protocols[] =
 { 66, 67, 68, 0 };
@@ -2367,7 +2360,7 @@
 	// cvar and command buffer management
 	Com_ParseCommandLine( commandLine );
 
-//	Swap_Init ();
+	Swap_Init ();
 	Cbuf_Init ();
 
 	Com_InitZoneMemory();
