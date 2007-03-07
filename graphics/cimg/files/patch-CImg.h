--- CImg.h.orig	Tue Mar  6 15:17:06 2007
+++ CImg.h	Wed Mar  7 21:14:51 2007
@@ -3777,7 +3777,7 @@
    */
   //! Class used to compute basic statistics on pixel values of a \ref CImg image.
   /**
-      Constructing a CImgStats instance from an image CImg<T> or a list CImgList<T>
+      Constructing a CImgStats instance from an image CImg&lt;T&gt; or a list CImgList&lt;T&gt;
       will compute the minimum, maximum and average pixel values of the input object.
       Optionally, the variance of the pixel values can be computed.
       Coordinates of the pixels whose values are minimum and maximum are also stored.
