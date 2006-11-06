--- CImg.h.orig	Mon Nov  6 15:26:08 2006
+++ CImg.h	Mon Nov  6 19:33:58 2006
@@ -20255,10 +20255,10 @@
   \ref cimg_library::cimg namespace as a default namespace, since it contains functions whose names are already
   defined in the standard C/C++ library.
 
-  - The class \ref cimg_library::CImg<T> represents images up to 4-dimensions wide, containing pixels of type \c T
+  - The class \ref cimg_library::CImg&lt;T&gt; represents images up to 4-dimensions wide, containing pixels of type \c T
   (template parameter). This is actually the main class of the library.
 
-  - The class \ref cimg_library::CImgList<T> represents lists of cimg_library::CImg<T> images. It can be used for instance
+  - The class \ref cimg_library::CImgList&lt;T&gt; represents lists of cimg_library::CImg&lt;T&gt; images. It can be used for instance
   to store different frames of an image sequence.
 
   - The class \ref cimg_library::CImgDisplay is able to display images or image lists into graphical display windows.
@@ -20411,16 +20411,16 @@
   compressed image format (GIF,PNG,...).
   See also cimg_library::CImg::get_load_convert() and cimg_library::CImg::save_convert() for more informations.
 
-  - \b \c cimg_plugin : This variable tells the library to use a plugin file to add features to the CImg<T> class.
-  Define it with the path of your plugin file, if you want to add member functions to the CImg<T> class,
-  without having to modify directly the \c "CImg.h" file. An include of the plugin file is performed in the CImg<T>
+  - \b \c cimg_plugin : This variable tells the library to use a plugin file to add features to the CImg&lt;T&gt; class.
+  Define it with the path of your plugin file, if you want to add member functions to the CImg&lt;T&gt; class,
+  without having to modify directly the \c "CImg.h" file. An include of the plugin file is performed in the CImg&lt;T&gt;
   class. If \c cimg_plugin if not specified (default), no include is done.
   
-  - \b \c cimglist_plugin : Same as \c cimg_plugin, but to add features to the CImgList<T> class.
+  - \b \c cimglist_plugin : Same as \c cimg_plugin, but to add features to the CImgList&lt;T&gt; class.
   
-  - \b \c cimgdisplay_plugin : Same as \c cimg_plugin, but to add features to the CImgDisplay<T> class.
+  - \b \c cimgdisplay_plugin : Same as \c cimg_plugin, but to add features to the CImgDisplay&lt;T&gt; class.
 
-  - \b \c cimgstats_plugin : Same as \c cimg_plugin, but to add features to the CImgStats<T> class.
+  - \b \c cimgstats_plugin : Same as \c cimg_plugin, but to add features to the CImgStats&lt;T&gt; class.
 
   All these compilation variables can be checked, using the function cimg_library::cimg::info(), which
   displays a list of the different configuration variables and their values on the standard error output.
@@ -20587,7 +20587,7 @@
   This macro loops over the pixel data buffer of the image \c img, using an offset \c ,
   starting from the beginning of the buffer (first pixel, \c off=0)
   till the end of the buffer (last pixel value, <tt>off = img.size()-1</tt>).
-      - \c img must be a (non empty) cimg_library::CImg<T> image of pixels \c T.
+      - \c img must be a (non empty) cimg_library::CImg&lt;T&gt; image of pixels \c T.
       - \c off is an inner-loop variable, only defined inside the scope of the loop.
 
   Here is an example of use :
@@ -20683,7 +20683,7 @@
 
   For all these loops, \c x and \c y are inner-defined variables only visible inside the scope of the loop.
   They don't have to be defined before the call of the macro.
-  \c img is a non empty CImg<T> image. \c z and \c v are constants that define on which image slice and
+  \c img is a non empty CImg&lt;T&gt; image. \c z and \c v are constants that define on which image slice and
   vector channel the loop must apply (usually both 0 for grayscale 2D images).
   Finally, \c I is the 2x2, 3x3, 4x4 or 5x5 neighborhood that will be updated with the correct pixel values
   during the loop (see \ref lo9).
@@ -20697,7 +20697,7 @@
 
   For all these loops, \c x, \c y and \c z are inner-defined variables only visible inside the scope of the loop.
   They don't have to be defined before the call of the macro.
-  \c img is a non empty CImg<T> image. \c v is a constant that defines on which image channel
+  \c img is a non empty CImg&lt;T&gt; image. \c v is a constant that defines on which image channel
   the loop must apply (usually 0 for grayscale 3D images).
   Finally, \c I is the 2x2x2 or 3x3x3 neighborhood that will be updated with the correct pixel values
   during the loop (see \ref lo9).
@@ -20741,7 +20741,7 @@
   values than the nearest valid pixel in the image (this is also called the \e Neumann \e border \e condition).
 
   \subsection lo10 Neighborhood as a reference
-  It is also possible to define neighborhood variables as references to classical C-arrays or CImg<T> images, instead of
+  It is also possible to define neighborhood variables as references to classical C-arrays or CImg&lt;T&gt; images, instead of
   allocating new variables. This is done by adding \c _ref to the macro names used for the neighborhood definition :
 
   - \b CImg_2x2x1_ref(I,type,tab) : Define a 2x2 neighborhood named \c I, of type \c type, as a reference to \c tab.
@@ -20751,7 +20751,7 @@
   - \b CImg_2x2x2_ref(I,type,tab) : Define a 2x2x2 neighborhood named \c I, of type \c type, as a reference to \c tab.
   - \b CImg_3x3x3_ref(I,type,tab) : Define a 3x3x3 neighborhood named \c I, of type \c type, as a reference to \c tab.
 
-  \c tab can be a one-dimensionnal C-style array, or a non empty \c CImg<T> image. Both objects must have
+  \c tab can be a one-dimensionnal C-style array, or a non empty \c CImg&lt;T&gt; image. Both objects must have
   same sizes as the considered neighborhoods.
 
   \subsection lo11 Example codes
