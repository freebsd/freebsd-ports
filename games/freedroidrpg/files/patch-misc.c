--- src/misc.c.orig	Mon Jul 18 02:13:52 2005
+++ src/misc.c		Mon Jul 18 02:19:36 2005
@@ -294,7 +294,7 @@
     // including the operating system (or rather libc) call to main() in 
     // the beginning of execution.
     //
-    backtrace_size = backtrace ( backtrace_array , MAX_CALLS_IN_BACKTRACE );
+    // backtrace_size = backtrace ( backtrace_array , MAX_CALLS_IN_BACKTRACE );
 
     fprintf ( stderr , "print_trace:  Obtained %zd stack frames.\n", backtrace_size );
     
@@ -307,7 +307,7 @@
     //       Also there might be a problem with non-ELF binaries, but let's
     //       hope that it still works...
     //
-    backtrace_strings = backtrace_symbols ( backtrace_array , backtrace_size );
+    // backtrace_strings = backtrace_symbols ( backtrace_array , backtrace_size );
     
     fprintf ( stderr , "print_trace:  Obtaining symbols now done.\n" );
     
