--- polyp/util.c.orig	Sun Nov 21 16:27:41 2004
+++ polyp/util.c	Tue Jan  4 17:13:51 2005
@@ -34,6 +34,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/socket.h>
 #include <pwd.h>
 #include <signal.h>
 #include <pthread.h>
@@ -285,7 +286,13 @@
     if ((e = getenv("HOME")))
         return pa_strlcpy(s, e, l);
 
+#ifdef HAVE_GETPWUID_R
     if (getpwuid_r(getuid(), &pw, buf, sizeof(buf), &r) != 0 || !r) {
+#else
+       /* XXX Not thead-safe, but needed on OSes (e.g. FreeBSD 4.X)
+        * that do not support getpwuid_r. */
+       if ((r = getpwuid(getuid())) == NULL) {
+#endif
         pa_log(__FILE__": getpwuid_r() failed\n");
         return NULL;
     }
