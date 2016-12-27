--- ap_client_main.cpp.orig	2012-08-14 00:07:20 UTC
+++ ap_client_main.cpp
@@ -241,7 +241,7 @@ int detect_hit(float *arr, float& total)
  * calls to this function.
  */
 void updatecputime() {
-  int cputicksinterval = abs(clock() - lastcputicks);
+  int cputicksinterval = abs((long)clock() - (long)lastcputicks);
   lastcputicks = clock();
   maxcputicksinterval = (maxcputicksinterval > cputicksinterval)?maxcputicksinterval:cputicksinterval;
   cputime += ((float)cputicksinterval / (float)CLOCKS_PER_SEC);
--- ap_client_main.cpp.orig	2012-08-14 00:07:20 UTC
+++ ap_client_main.cpp
@@ -1288,7 +1288,6 @@ void Science::mainloop() {
                * used to inform the core client GUI of the % complete.
                */
               boinc_fraction_done(state.frac_done);
-	      boinc_ops_cumulative(state.frac_done*FLOPS_PER_DM*(state.dm_hi-state.dm_low)*log((float)state.fft_len)/log(32768.0),0);
               debug_loop(5, 2, debug_loop_msg);
   
               /* This is the size of the power array.
