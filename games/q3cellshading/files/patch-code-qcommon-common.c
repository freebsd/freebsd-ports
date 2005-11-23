--- code/qcommon/common.c.orig	Mon Aug 15 23:10:07 2005
+++ code/qcommon/common.c	Wed Nov 23 10:53:29 2005
@@ -24,15 +24,8 @@
 #include "../game/q_shared.h"
 #include "qcommon.h"
 #include <setjmp.h>
-#ifdef __linux__
+#include <sys/types.h>
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
