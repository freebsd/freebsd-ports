--- ap_fold.cpp.orig	2009-04-01 02:11:24.000000000 +0200
+++ ap_fold.cpp	2013-08-06 18:42:02.000000000 +0200
@@ -283,7 +283,6 @@
        * used to inform the core client GUI of the % complete.
        */
       boinc_fraction_done(state.frac_done);
-      boinc_ops_cumulative(state.frac_done*FLOPS_PER_DM*(state.dm_hi-state.dm_low)*log((double)state.fft_len)/log(32768.0),0);
 
       freq_count++;
       /* Report to stdout if we have reached a new "milestone" frequency. */
