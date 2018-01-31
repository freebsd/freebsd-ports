--- mono/profiler/ptestrunner.pl.orig	2017-07-20 18:10:59 UTC
+++ mono/profiler/ptestrunner.pl
@@ -103,8 +103,6 @@ check_alloc_traces ($report,
 );
 report_errors ();
 
-emit_nunit_report();
-
 exit ($global_errors ? 1 : 0);
 
 # utility functions
