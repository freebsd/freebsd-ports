--- client/worker.cpp.orig	2008-07-31 02:02:10.000000000 +0200
+++ client/worker.cpp	2013-08-06 18:48:48.000000000 +0200
@@ -153,7 +153,6 @@
     retval = seti_do_work();
     if (retval) SETIERROR(retval,"from seti_do_work() in worker()");
 
-    boinc_fpops_cumulative((SETUP_FLOPS+analysis_state.FLOP_counter)*LOAD_STORE_ADJUSTMENT);
     boinc_finish(retval);
   }
   catch (seti_error e) {
@@ -165,7 +164,6 @@
 	remaining=0;
 	boinc_fraction_done(progress);
         checkpoint(true);      // force a checkpoint
-        boinc_fpops_cumulative((SETUP_FLOPS+analysis_state.FLOP_counter)*LOAD_STORE_ADJUSTMENT);
         boinc_finish(0);
         exit(0);            // an overflow is not an app error
     } else {
