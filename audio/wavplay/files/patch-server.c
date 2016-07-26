--- server.c.orig	1999-12-04 00:06:42 UTC
+++ server.c
@@ -65,7 +65,9 @@ static const char rcsid[] = "@(#)server.
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifndef FREEBSD
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -79,7 +81,11 @@ static const char rcsid[] = "@(#)server.
 #ifdef SCHED_PRIORITY
 #include <sched.h>
 #endif
+#ifndef FREEBSD
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include "wavplay.h"
 #include "server.h"
 
