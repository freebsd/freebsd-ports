--- src/os/pl-file.c.orig	2026-06-16 17:23:46 UTC
+++ src/os/pl-file.c
@@ -67,7 +67,7 @@ - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 #include "../pl-trace.h"
 #include <errno.h>
 
-#if defined(HAVE_POLL_H) && defined(HAVE_POLL)
+#if defined(HAVE_POLL)
 #include <poll.h>
 #elif defined(HAVE_SYS_SELECT_H)
 #include <sys/select.h>
