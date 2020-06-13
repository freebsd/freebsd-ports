--- CImg.h.orig	2020-06-10 08:03:38 UTC
+++ CImg.h
@@ -28530,7 +28530,7 @@ namespace cimg_library_suffixed {
                        "solve(): LAPACK library function dgetrf_() returned error code %d.",
                        cimg_instance,
                        INFO);
-          if (!INFO) {
+          else {
             cimg::getrs(TRANS,N,lapA,IPIV,lapB,INFO);
             if (INFO)
               cimg::warn(_cimg_instance
@@ -28538,7 +28538,7 @@ namespace cimg_library_suffixed {
                          cimg_instance,
                          INFO);
           }
-          if (!INFO) cimg_forY(*this,j) (*this)(i,j) = (T)(lapB[j]); else cimg_forY(*this,i,j) (*this)(i,j) = (T)0;
+          if (!INFO) cimg_forY(*this,j) (*this)(i,j) = (T)(lapB[j]); else cimg_forY(*this,j) (*this)(i,j) = (T)0;
         }
         delete[] IPIV; delete[] lapA; delete[] lapB; delete[] WORK;
 #else
