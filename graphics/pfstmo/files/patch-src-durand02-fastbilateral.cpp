--- src/durand02/fastbilateral.cpp.orig	2008-09-09 18:10:49.000000000 +0000
+++ src/durand02/fastbilateral.cpp	2014-06-18 15:29:52.288954426 +0000
@@ -66,11 +66,11 @@
   {
     int ox = nx;
     int oy = ny/2 + 1;            // saves half of the data
-    const int osize = ox * oy;
-    source =  (float*)fftwf_malloc(sizeof(float) * nx * 2 * (ny/2+1) );
+    const size_t osize = ox * oy;
+    source =  (float*)fftwf_malloc(sizeof(float) * (size_t)nx * 2 * ((size_t)ny/2+1) );
     freq = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * osize);
-//    if( source == NULL || freq == NULL )
-    //TODO: throw exception
+    if( source == NULL || freq == NULL )
+        throw std::bad_alloc();
     fplan_fw = fftwf_plan_dft_r2c_2d(nx, ny, source, freq, FFTW_ESTIMATE);
     fplan_in = fftwf_plan_dft_c2r_2d(nx, ny, freq, source, FFTW_ESTIMATE);    
   }
@@ -100,7 +100,7 @@
     for( x=0 ; x<ox/2 ; x++ )
       for( y=0 ; y<oy ; y++ )
       {
-        float d2 = x*x + y*y;
+        float d2 = (float)x*x + (float)y*y;
         float kernel = exp( -d2 / sig2 );
         
         freq[x*oy+y][0] *= kernel;
