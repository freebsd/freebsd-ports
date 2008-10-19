--- src/fgrun_pty.cxx.orig	2008-10-18 17:32:33.000000000 +0800
+++ src/fgrun_pty.cxx	2008-10-18 17:33:12.000000000 +0800
@@ -28,6 +28,9 @@
 #  include <pty.h>
 #endif
 
+#include <sys/types.h>
+#include <libutil.h>
+
 #if defined(HAVE_UTMP_H)
 #  include <utmp.h>
 #endif
