--- ./modules/ts/src/ts.cpp.orig	2013-10-26 08:01:35.000000000 -0400
+++ ./modules/ts/src/ts.cpp	2013-10-26 08:02:28.000000000 -0400
@@ -562,7 +562,7 @@
     for( int i = 0; i < MAX_IDX; i++ )
         if( (streams & (1 << i)) )
         {
-            output_buf[i] += std::string(str);
+            output_buf[i] += ::std::string(str);
             // in the new GTest-based framework we do not use
             // any output files (except for the automatically generated xml report).
             // if a test fails, all the buffers are printed, so we do not want to duplicate the information and
@@ -617,7 +617,7 @@
     Scalar s;
     uchar *p = NULL;
     int n = 100/delta;
-    int nR = std::min(n, (img.rows+1)/2), nC = std::min(n, (img.cols+1)/2);
+    int nR = ::std::min(n, (img.rows+1)/2), nC = std::min(n, (img.cols+1)/2);
 
     int r, c, i;
     for(r=0; r<nR; r++)
