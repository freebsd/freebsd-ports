--- runner/executor.c.orig	2022-08-31 20:00:01 UTC
+++ runner/executor.c
@@ -2,7 +2,9 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <glib.h>
+#ifdef __linux__
 #include <linux/watchdog.h>
+#endif
 #if HAVE_OPING
 #include <oping.h>
 #endif
@@ -14,7 +16,9 @@
 #include <sys/ioctl.h>
 #include <sys/select.h>
 #include <sys/poll.h>
+#ifdef __linux__
 #include <sys/signalfd.h>
+#endif
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -32,6 +36,16 @@
 
 #define KMSG_HEADER "[IGT] "
 #define KMSG_WARN 4
+
+#ifdef __FreeBSD__
+#include <sys/watchdog.h>
+struct signalfd_siginfo {
+	uint32_t ssi_signo;
+	uint32_t ssi_pid;
+};
+#define	WDIOC_KEEPALIVE			WDIOCPATPAT
+#define	signalfd(fd, mask, flags)	-ENOSYS
+#endif
 
 static struct {
 	int *fds;
