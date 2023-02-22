--- afcsub.c.orig	2023-02-21 23:02:52 UTC
+++ afcsub.c
@@ -692,7 +692,7 @@ int make_afc_signoi(void)
 
 int make_afc_signoi(void)
 {
-int i, k, np,j;
+int i, k, np;
 float t1,t2;
 // Estimate S/N for the signal we see in mix1_eval data.
 // Last time we used ag.fit_points blocks of eval data to evaluate
@@ -765,10 +765,8 @@ i=np;
 if(t2 > 0.25*t1)t2=0.25*t1;
 k=0;
 i=np;
-j=0;
 while(i != fftx_na)
   {
-  j++;
   if(mix1_eval_avgn[mix1p0+i]>0)
     {
     if(mix1_eval_sigpwr[mix1p0+i]>t2)
