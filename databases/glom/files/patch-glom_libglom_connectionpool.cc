--- glom/libglom/connectionpool.cc.orig	2008-04-29 18:10:54.000000000 +0200
+++ glom/libglom/connectionpool.cc	2008-08-08 02:39:55.000000000 +0200
@@ -789,7 +789,11 @@ bool ConnectionPool::directory_exists_ur
 // TODO: This is probably mingw specific
 static __p_sig_fn_t previous_sig_handler = SIG_DFL;
 #else
+#  ifdef __FreeBSD__
+static __sighandler_t *previous_sig_handler = SIG_DFL; /* Arbitrary default */
+#  else
 static sighandler_t previous_sig_handler = SIG_DFL; /* Arbitrary default */
+#  endif
 #endif
 
 /* This is a Linux/Unix signal handler, 
