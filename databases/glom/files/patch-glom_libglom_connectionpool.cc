--- glom/libglom/connectionpool.cc.orig	2008-01-31 11:29:29.000000000 +0100
+++ glom/libglom/connectionpool.cc	2008-01-31 11:38:06.000000000 +0100
@@ -642,7 +642,7 @@ bool ConnectionPool::directory_exists_ur
 }
 
 #ifndef GLOM_ENABLE_CLIENT_ONLY
-static sighandler_t previous_sig_handler = SIG_DFL; /* Arbitrary default */
+static __sighandler_t *previous_sig_handler = SIG_DFL; /* Arbitrary default */
 
 /* This is a Linux/Unix signal handler, 
  * so we can respond to a crash.
