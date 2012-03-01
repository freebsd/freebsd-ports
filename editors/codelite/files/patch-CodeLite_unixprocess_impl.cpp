--- CodeLite/unixprocess_impl.cpp.orig	2011-10-11 18:58:27.000000000 +0200
+++ CodeLite/unixprocess_impl.cpp	2012-02-17 17:14:25.000000000 +0100
@@ -15,8 +15,14 @@
 #include "procutils.h"
 
 #ifdef __WXGTK__
+#ifdef __FreeBSD__
+#    include <sys/ioctl.h>
+#    include <termios.h>
+#    include <libutil.h>
+#else
 #    include <pty.h>
 #    include <utmp.h>
+#endif
 #else
 #    include <util.h>
 #endif
