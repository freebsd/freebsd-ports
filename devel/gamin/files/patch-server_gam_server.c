--- server/gam_server.c.orig	Thu Dec  2 12:42:56 2004
+++ server/gam_server.c	Sun Mar 27 02:34:19 2005
@@ -39,12 +39,29 @@
 #ifdef ENABLE_DNOTIFY
 #include "gam_dnotify.h"
 #endif
+#ifdef ENABLE_KQUEUE
+#include "gam_kqueue.h"
+#endif
 #include "gam_excludes.h"
 
 static int poll_only = 0;
 static const char *session;
 
 /**
+ * gam_exit:
+ *
+ * Call the shutdown routine, then just exit.
+ * This function is designed to be called from a
+ * signal handler.
+ */
+void
+gam_exit(int signo) {
+	gam_shutdown();
+
+	exit(0);
+}
+
+/**
  * gam_shutdown:
  *
  * Shutdown routine called when the server exits
@@ -90,6 +107,12 @@ gam_init_subscriptions(void)
 	    return(TRUE);
 	}
 #endif
+#ifdef ENABLE_KQUEUE
+	if (gam_kqueue_init()) {
+	    GAM_DEBUG(DEBUG_INFO, "Using KQueue as backend\n");
+	    return(TRUE);
+	}
+#endif
     }
     if (gam_poll_init()) {
 	GAM_DEBUG(DEBUG_INFO, "Using Poll as backend\n");
@@ -332,6 +355,10 @@ main(int argc, const char *argv[])
     }
 
     gam_error_init();
+    signal(SIGHUP, gam_exit);
+    signal(SIGINT, gam_exit);
+    signal(SIGQUIT, gam_exit);
+    signal(SIGTERM, gam_exit);
     signal(SIGPIPE, SIG_IGN);
 
     if (!gam_init_subscriptions()) {
