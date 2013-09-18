--- ap_client_main.cpp.orig	2012-08-14 02:07:20.000000000 +0200
+++ ap_client_main.cpp	2013-08-06 18:41:38.000000000 +0200
@@ -1288,7 +1288,6 @@
                * used to inform the core client GUI of the % complete.
                */
               boinc_fraction_done(state.frac_done);
-	      boinc_ops_cumulative(state.frac_done*FLOPS_PER_DM*(state.dm_hi-state.dm_low)*log((float)state.fft_len)/log(32768.0),0);
               debug_loop(5, 2, debug_loop_msg);
   
               /* This is the size of the power array.
