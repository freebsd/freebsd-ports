--- sysdeps/freebsd/glibtop_machine.h.orig	2009-12-13 18:34:21.000000000 -0500
+++ sysdeps/freebsd/glibtop_machine.h	2009-12-13 18:34:32.000000000 -0500
@@ -24,6 +24,7 @@
 
 #include <sys/param.h>
 #include <nlist.h>
+#include <limits.h>
 #include <kvm.h>
 #include <sys/dkstat.h>
 #include <time.h>
