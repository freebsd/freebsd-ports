--- sql/mysqld.cc       2011-02-28 17:39:30 +0000
+++ sql/mysqld.cc       2011-03-04 10:39:27 +0000
@@ -744,9 +744,7 @@
 /* Static variables */

 static bool kill_in_progress, segfaulted;
-#ifdef HAVE_STACKTRACE
 static my_bool opt_stack_trace;
-#endif /* HAVE_STACKTRACE */
 static my_bool opt_bootstrap, opt_myisam_log;
 static int cleanup_done;
 static ulong opt_specialflag, opt_myisam_block_size;


