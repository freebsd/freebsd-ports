--- CodeLite/unixprocess_impl.cpp.orig	2010-11-11 11:14:08.000000000 +0000
+++ CodeLite/unixprocess_impl.cpp	2010-11-11 11:14:57.000000000 +0000
@@ -12,8 +12,14 @@
 #include <sys/wait.h>
 
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
