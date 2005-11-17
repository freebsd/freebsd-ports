diff -ruN ./code/qcommon/common.c ../quake3-1.32b-BUILT/./code/qcommon/common.c
--- ./code/qcommon/common.c	Tue Aug 16 02:10:07 2005
+++ ../quake3-1.32b-BUILT/./code/qcommon/common.c	Mon Aug 22 21:03:32 2005
@@ -24,15 +24,7 @@
 #include "../game/q_shared.h"
 #include "qcommon.h"
 #include <setjmp.h>
-#ifdef __linux__
 #include <netinet/in.h>
-#else
-#if defined(MACOS_X)
-#include <netinet/in.h>
-#else
-#include <winsock.h>
-#endif
-#endif
 
 int demo_protocols[] =
 { 66, 67, 68, 0 };
