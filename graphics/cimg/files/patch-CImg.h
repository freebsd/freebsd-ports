--- CImg.h.orig	2019-03-10 13:46:23 UTC
+++ CImg.h
@@ -26529,7 +26529,6 @@ namespace cimg_library_suffixed {
           cimg_forXY(vec,k,l) vec(k,l) = (T)(lapA[(N - 1 - k)*N + l]);
         } else { val.fill(0); vec.fill(0); }
         delete[] lapA; delete[] lapW; delete[] WORK;
-        sort_eigenvalues = false;
 #else
 
 	val.assign(1,_width);
