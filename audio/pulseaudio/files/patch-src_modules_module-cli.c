--- src/modules/module-cli.c.orig	2009-09-19 13:57:53.000000000 -0400
+++ src/modules/module-cli.c	2009-09-19 14:04:25.000000000 -0400
@@ -105,7 +105,12 @@ int pa__init(pa_module*m) {
      * of log messages, particularly because if stdout and stderr are
      * dup'ed they share the same O_NDELAY, too. */
 
+#ifdef O_CLOEXEC
     if ((fd = open("/dev/tty", O_RDWR|O_CLOEXEC|O_NONBLOCK)) >= 0) {
+#else
+    if ((fd = open("/dev/tty", O_RDWR|O_NONBLOCK)) >= 0 &&
+        fcntl(fd, F_SETFD, FD_CLOEXEC) != -1) {
+#endif
         io = pa_iochannel_new(m->core->mainloop, fd, fd);
         pa_log_debug("Managed to open /dev/tty.");
     } else {
