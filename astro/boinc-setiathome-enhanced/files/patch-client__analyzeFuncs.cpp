--- client/analyzeFuncs.cpp.orig	2008-07-31 02:02:10.000000000 +0200
+++ client/analyzeFuncs.cpp	2013-08-06 18:48:46.000000000 +0200
@@ -415,7 +415,6 @@
         fftlen    = ChirpFftPairs[icfft].FftLen;
         chirprate = ChirpFftPairs[icfft].ChirpRate;
         chirprateind = ChirpFftPairs[icfft].ChirpRateInd;
-        boinc_fpops_cumulative((SETUP_FLOPS+analysis_state.FLOP_counter)*LOAD_STORE_ADJUSTMENT);
         // boinc_worker_timer();
 #ifdef DEBUG
         double ptime=static_cast<double>((unsigned)clock())/CLOCKS_PER_SEC+
