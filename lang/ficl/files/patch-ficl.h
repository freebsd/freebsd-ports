--- ficl.h.orig	2010-10-03 09:52:12 UTC
+++ ficl.h
@@ -163,6 +163,8 @@ extern "C" {
 	#include "ficlplatform/ansi.h"
 #elif defined(_WIN32)
 	#include "ficlplatform/win32.h"
+#elif defined (FREEBSD)
+	#include "ficlplatform/unix.h"
 #elif defined (FREEBSD_ALPHA)
 	#include "ficlplatform/alpha.h"
 #elif defined(unix) || defined(__unix__) || defined(__unix)
