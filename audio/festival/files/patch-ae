$NetBSD: patch-ae,v 1.2 1999/10/11 14:13:49 proff Exp $

--- speech_tools/include/EST_unix.h	Sun May 30 20:53:04 1999
+++ speech_tools/include/EST_unix.h	Mon Oct 11 05:40:15 1999
@@ -53,6 +53,7 @@
 #   include <sys/wait.h>
 #   include <sys/resource.h>
 #   include <dirent.h>
+#   define unix 1
 #elif defined(SYSTEM_IS_WIN32)
 #   include <io.h>
 #   include "win32/EST_unix_win32.h"
