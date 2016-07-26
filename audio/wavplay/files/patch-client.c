--- client.c.orig	1999-12-04 00:06:42 UTC
+++ client.c
@@ -47,7 +47,9 @@ static const char rcsid[] = "@(#)client.
 #include <unistd.h>
 #include <errno.h>
 #include <time.h>
+#ifndef FREEBSD
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -57,7 +59,11 @@ static const char rcsid[] = "@(#)client.
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <assert.h>
+#ifndef FREEBSD
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include "wavplay.h"
 #include "client.h"
 
