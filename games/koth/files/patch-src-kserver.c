--- src/kserver.c.orig	Wed Feb  5 03:39:03 2003
+++ src/kserver.c	Sat Oct 16 20:42:55 2004
@@ -21,6 +21,7 @@
 #include <string.h>
 #include <time.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <signal.h>
 #include <assert.h>
@@ -31,7 +32,6 @@
 #	include <sys/select.h>
 #else
 #	include <sys/time.h>
-#	include <sys/types.h>
 #endif
 #include "player.h"
 #include "relay.h"
