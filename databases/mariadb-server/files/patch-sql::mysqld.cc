--- sql/mysqld.cc.orig	2011-03-01 22:24:07.000000000 -0800
+++ sql/mysqld.cc	2011-05-31 16:50:56.000000000 -0700
@@ -744,9 +744,7 @@
 /* Static variables */
 
 static bool kill_in_progress, segfaulted;
-#ifdef HAVE_STACKTRACE
 static my_bool opt_stack_trace;
-#endif /* HAVE_STACKTRACE */
 static my_bool opt_bootstrap, opt_myisam_log;
 static int cleanup_done;
 static ulong opt_specialflag, opt_myisam_block_size;
