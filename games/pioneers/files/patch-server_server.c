--- server/server.c.orig	Fri Jan 21 17:02:43 2005
+++ server/server.c	Fri Jan 21 17:06:15 2005
@@ -30,6 +30,8 @@
 #include <errno.h>
 #include <string.h>
 #include <time.h>
+#include <netinet/in.h>
+#include <sys/signal.h>
 
 #ifndef HAVE_G_RAND_NEW_WITH_SEED
 #include "mt_rand.h"
