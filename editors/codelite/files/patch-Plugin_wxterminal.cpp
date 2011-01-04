--- Plugin/wxterminal.cpp.orig	2011-01-03 17:42:09.000000000 +0100
+++ Plugin/wxterminal.cpp	2011-01-03 17:43:05.000000000 +0100
@@ -21,7 +21,13 @@
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
