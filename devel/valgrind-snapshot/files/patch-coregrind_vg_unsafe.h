--- coregrind/vg_unsafe.h.orig	Sun Feb  4 20:04:39 2007
+++ coregrind/vg_unsafe.h	Sun Feb  4 20:05:29 2007
@@ -124,7 +124,7 @@
 #include <sys/times.h>
 #include <sys/timex.h>
 #include <sys/event.h>
-#include <posix4/sched.h>
+#include <sched.h>
 #include <net/if.h>
 #include <net/route.h>
 #include <netinet/in.h>
