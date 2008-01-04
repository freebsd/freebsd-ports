--- kernel/OS/FreeBSD/os_freebsd.c.orig	2008-01-04 17:47:28.000000000 -0500
+++ kernel/OS/FreeBSD/os_freebsd.c	2008-01-04 17:47:30.000000000 -0500
@@ -21,6 +21,7 @@
 #include <sys/proc.h>
 #include <sys/sx.h>
 #include <sys/mman.h>
+#include <sys/lockmgr.h>
 #include <fs/devfs/devfs.h>
 #include <sys/poll.h>
 
