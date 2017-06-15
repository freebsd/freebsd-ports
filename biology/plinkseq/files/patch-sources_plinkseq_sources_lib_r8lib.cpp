--- sources/plinkseq/sources/lib/r8lib.cpp.orig	2014-07-09 14:37:16 UTC
+++ sources/plinkseq/sources/lib/r8lib.cpp
@@ -31828,7 +31828,7 @@ void r8vec_index_sorted_range ( int n, d
   if ( r_hi < r[indx[*i_hi]] )
   {
     *i_hi = *i_hi - 1;
-    if ( i_hi < 0 )
+    if ( *i_hi < 0 )
     {
       *i_lo = *i_hi + 1;
     }
