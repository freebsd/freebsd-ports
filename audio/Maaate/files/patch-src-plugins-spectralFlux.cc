--- src/plugins/spectralFlux.cc.orig	Wed Jan 23 12:22:13 2002
+++ src/plugins/spectralFlux.cc	Sat Jul 20 17:21:11 2002
@@ -182,9 +182,9 @@
 
   //temporary results
   int SBM = mf->nb_subbands(LOW);
-  double temp[SBM];
-  double old_temp[SBM];
-  double (* aux)[SBM];
+  double btemp[SBM];
+  double bold_temp[SBM];
+  double *temp = btemp, *old_temp = bold_temp, **aux;
   double max = 0.0;
 
 
