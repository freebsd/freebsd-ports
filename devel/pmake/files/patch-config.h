--- unix/config.h.orig	Tue Jun  4 21:35:28 2002
+++ unix/config.h	Tue Jun  4 21:34:59 2002
@@ -208,6 +208,11 @@
 # define HAVE_POSIX
 #endif /* SYSV */
 
+#include <sys/param.h>
+#ifdef __FreeBSD__
+# define HAVE_POSIX
+#endif
+
 #define LIBTOC		"__.SYMDEF"
 #define LIBFLAG		"-l"
 #define LIBPREFIX	"lib"
