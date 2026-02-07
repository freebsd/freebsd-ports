--- afc_graph.c.orig	2014-11-04 10:25:00 UTC
+++ afc_graph.c
@@ -71,7 +71,9 @@ void make_afc_graph(int clear_old);
 int afc_fit_line(void)
 {
 int i,j,k, np;
-float t1, t2, wfq, ston_avgsumsq, r1, r2;
+float t1, t2, wfq, ston_avgsumsq;
+float r1;
+
 // Make an S/N weighted least squares fit of a straight line
 // to mix1_eval_fq from fftx_nf1 to fftx_nf2.
 // First store weights ( S/N ) in afc_spectrum which can 
@@ -174,7 +176,7 @@ if(llsq1() != 0)
 // Also calculate under assumption we adopted the average frequency wfq.
 t1=0;
 t2=0;
-r2=0;
+//r2=0;
 np=fftx_nf1;
 afc_slope=llsq_steps[1];
 for(i=0; i<ag.fit_points; i++)
@@ -185,7 +187,7 @@ for(i=0; i<ag.fit_points; i++)
   mix1_fitted_fq[mix1p0+np]=r1;
   t1+=(float)pow((r1-mix1_eval_fq[mix1p0+np]),2.0)*afc_spectrum[i];
   t2+=(float)pow((wfq-mix1_eval_fq[mix1p0+np]),2.0)*afc_spectrum[i];
-  r2+=(float)pow((mix1_good_freq[ag_ss]-mix1_eval_fq[mix1p0+np]),2.0)*afc_spectrum[i];
+  //  r2+=(float)pow((mix1_good_freq[ag_ss]-mix1_eval_fq[mix1p0+np]),2.0)*afc_spectrum[i];
   np=(np+1)&fftxn_mask;
   }
 // t1, t2 and r2 are sums of squared errors.
