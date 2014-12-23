--- src/inotify.c.orig	2014-12-23 15:46:08 UTC
+++ src/inotify.c
@@ -15,9 +15,9 @@
 */
 
 #include "dnsmasq.h"
-#include <sys/inotify.h>
 
 #ifdef HAVE_LINUX_NETWORK
+#include <sys/inotify.h>
 
 /* the strategy is to set a inotify on the directories containing
    resolv files, for any files in the directory which are close-write 
