https://github.com/karlheyes/icecast-kh/pull/231

--- src/auth_cmd.c.orig	2018-08-29 15:48:26 UTC
+++ src/auth_cmd.c
@@ -35,9 +35,7 @@
 #ifdef HAVE_POLL
 #include <poll.h>
 #endif
-#ifdef HAVE_SIGNAL_H
 #include <signal.h>
-#endif
 
 #include "auth.h"
 #include "util.h"
