--- CImg.h.orig	Mon Mar  5 18:56:32 2007
+++ CImg.h	Mon Mar  5 20:47:05 2007
@@ -3778,7 +3778,7 @@
    */
   //! Class used to compute basic statistics on pixel values of a \ref CImg image.
   /**
-      Constructing a CImgStats instance from an image CImg<T> or a list CImgList<T>
+      Constructing a CImgStats instance from an image CImg&lt;T&gt; or a list CImgList&lt;T&gt;
       will compute the minimum, maximum and average pixel values of the input object.
       Optionally, the variance of the pixel values can be computed.
       Coordinates of the pixels whose values are minimum and maximum are also stored.
@@ -21622,10 +21622,10 @@
   \ref cimg_library::cimg namespace as a default namespace, since it contains functions whose names are already
   defined in the standard C/C++ library.
 
-  - The class \ref cimg_library::CImg<T> represents images up to 4-dimensions wide, containing pixels of type \c T
+  - The class \ref cimg_library::CImg&lt;T&gt; represents images up to 4-dimensions wide, containing pixels of type \c T
   (template parameter). This is actually the main class of the library.
 
-  - The class \ref cimg_library::CImgList<T> represents lists of cimg_library::CImg<T> images. It can be used for instance
+  - The class \ref cimg_library::CImgList&lt;T&gt; represents lists of cimg_library::CImg&lt;T&gt; images. It can be used for instance
   to store different frames of an image sequence.
 
   - The class \ref cimg_library::CImgDisplay is able to display images or image lists into graphical display windows.
@@ -21966,7 +21966,7 @@
   This macro loops over the pixel data buffer of the image \c img, using an offset \c ,
   starting from the beginning of the buffer (first pixel, \c off=0)
   till the end of the buffer (last pixel value, <tt>off = img.size()-1</tt>).
-      - \c img must be a (non empty) cimg_library::CImg<T> image of pixels \c T.
+      - \c img must be a (non empty) cimg_library::CImg&lt;T&gt; image of pixels \c T.
       - \c off is an inner-loop variable, only defined inside the scope of the loop.
 
   Here is an example of use :
@@ -22062,7 +22062,7 @@
 
   For all these loops, \c x and \c y are inner-defined variables only visible inside the scope of the loop.
   They don't have to be defined before the call of the macro.
-  \c img is a non empty CImg<T> image. \c z and \c v are constants that define on which image slice and
+  \c img is a non empty CImg&lt;T&gt; image. \c z and \c v are constants that define on which image slice and
   vector channel the loop must apply (usually both 0 for grayscale 2D images).
   Finally, \c I is the 2x2, 3x3, 4x4 or 5x5 neighborhood that will be updated with the correct pixel values
   during the loop (see \ref lo9).
@@ -22076,7 +22076,7 @@
 
   For all these loops, \c x, \c y and \c z are inner-defined variables only visible inside the scope of the loop.
   They don't have to be defined before the call of the macro.
-  \c img is a non empty CImg<T> image. \c v is a constant that defines on which image channel
+  \c img is a non empty CImg&lt;T&gt; image. \c v is a constant that defines on which image channel
   the loop must apply (usually 0 for grayscale 3D images).
   Finally, \c I is the 2x2x2 or 3x3x3 neighborhood that will be updated with the correct pixel values
   during the loop (see \ref lo9).
@@ -22120,7 +22120,7 @@
   values than the nearest valid pixel in the image (this is also called the \e Neumann \e border \e condition).
 
   \subsection lo10 Neighborhood as a reference
-  It is also possible to define neighborhood variables as references to classical C-arrays or CImg<T> images, instead of
+  It is also possible to define neighborhood variables as references to classical C-arrays or CImg&lt;T&gt; images, instead of
   allocating new variables. This is done by adding \c _ref to the macro names used for the neighborhood definition :
 
   - \b CImg_2x2x1_ref(I,type,tab) : Define a 2x2 neighborhood named \c I, of type \c type, as a reference to \c tab.
@@ -22130,7 +22130,7 @@
   - \b CImg_2x2x2_ref(I,type,tab) : Define a 2x2x2 neighborhood named \c I, of type \c type, as a reference to \c tab.
   - \b CImg_3x3x3_ref(I,type,tab) : Define a 3x3x3 neighborhood named \c I, of type \c type, as a reference to \c tab.
 
-  \c tab can be a one-dimensionnal C-style array, or a non empty \c CImg<T> image. Both objects must have
+  \c tab can be a one-dimensionnal C-style array, or a non empty \c CImg&lt;T&gt; image. Both objects must have
   same sizes as the considered neighborhoods.
 
   \subsection lo11 Example codes
