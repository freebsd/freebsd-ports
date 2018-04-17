--- src/cdflib.cpp.orig	2018-03-09 20:31:19 UTC
+++ src/cdflib.cpp
@@ -10040,7 +10040,7 @@ void negative_binomial_cdf_values ( int 
     1, 2, 3,
     0, 1, 2 };
 
-  if ( n_data < 0 )
+  if ( *n_data < 0 )
   {
     *n_data = 0;
   }
