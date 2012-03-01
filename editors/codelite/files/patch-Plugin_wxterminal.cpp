--- Plugin/wxterminal.cpp.orig	2011-06-09 22:23:36.000000000 +0200
+++ Plugin/wxterminal.cpp	2012-02-17 17:15:06.000000000 +0100
@@ -22,7 +22,13 @@
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
