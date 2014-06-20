--- src/responses.cpp.orig	2006-09-13 14:27:06.000000000 +0000
+++ src/responses.cpp	2014-06-18 15:27:14.298952630 +0000
@@ -63,6 +63,7 @@
 {
   float mid = Mmin + (Mmax-Mmin)/2.0f - 0.5f;
   float mid2 = (mid-Mmin) * (mid-Mmin);
+  std::cerr << "Mmin: " << Mmin << "; mid: " << mid << "; Mmax: " << Mmax << "; M: " << M << "; sigma: " << sigma << std::endl;
   for( int m=0 ; m<M ; m++ )
     if( m<Mmin || m>Mmax )
       w[m] = 0.0f;
