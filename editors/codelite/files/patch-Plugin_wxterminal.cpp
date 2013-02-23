--- Plugin/wxterminal.cpp.orig	2013-01-12 18:39:52.000000000 +0100
+++ Plugin/wxterminal.cpp	2013-02-01 14:55:54.000000000 +0100
@@ -23,7 +23,13 @@
 #endif
 
 #if defined(__WXGTK__)
+#ifdef __FreeBSD__
+#    include <sys/ioctl.h>
+#    include <termios.h>
+#    include <libutil.h>
+#else
 #    include <pty.h>
+#endif
 #    include "unixprocess_impl.h"
 #elif defined(__WXMAC__)
 #    include <util.h>
