--- platforms/unix/plugins/PseudoTTYPlugin/openpty.h.orig	Tue Jan 14 16:02:55 2003
+++ platforms/unix/plugins/PseudoTTYPlugin/openpty.h	Tue Jan 14 16:03:09 2003
@@ -45,7 +45,10 @@
 # elif defined(HAVE_LIBUTIL_H)
 #   include <libutil.h>		/* openpty() on FreeBSD */
 # else
-#   error: cannot find headers for openpty()
+#   include <sys/types.h>
+#   include <sys/ioctl.h>
+#   include <termios.h>
+#   include <libutil.h>
 # endif
 
 #else /* !HAVE_OPENPTY */
