--- ap_fold.cpp.orig	2009-04-01 00:11:24 UTC
+++ ap_fold.cpp
@@ -283,7 +283,6 @@ int Science::ffa(float *data, int num_su
        * used to inform the core client GUI of the % complete.
        */
       boinc_fraction_done(state.frac_done);
-      boinc_ops_cumulative(state.frac_done*FLOPS_PER_DM*(state.dm_hi-state.dm_low)*log((double)state.fft_len)/log(32768.0),0);
 
       freq_count++;
       /* Report to stdout if we have reached a new "milestone" frequency. */
