--- ficl.h.orig	Mon Dec  8 18:33:42 2003
+++ ficl.h	Mon Dec  8 18:33:58 2003
@@ -163,6 +163,8 @@
 	#include "ficlplatform/ansi.h"
 #elif defined(_WIN32)
 	#include "ficlplatform/win32.h"
+#elif defined (FREEBSD)
+	#include "ficlplatform/unix.h"
 #elif defined (FREEBSD_ALPHA)
 	#include "ficlplatform/alpha.h"
 #elif defined(linux)
