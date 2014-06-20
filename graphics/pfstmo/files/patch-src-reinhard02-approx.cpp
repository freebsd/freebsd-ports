--- src/reinhard02/approx.cpp.orig	2007-06-14 16:41:30.000000000 +0000
+++ src/reinhard02/approx.cpp	2014-06-18 15:29:52.308951834 +0000
@@ -17,36 +17,36 @@
 #include <stdio.h>
 #include <math.h>
 
+#include <pfstmo.h>
+
 // interpolated version of approximation (always use this one!) (:krawczyk)
 #define INTERPOLATED
 
-extern double **luminance; 
-int      ImageWidth, ImageHeight;
+extern pfstmo::Array2D *lum;
+extern int             width, height;
 
-double ***Pyramid;
-int       PyramidHeight;
-int       PyramidWidth0;
+int PyramidHeight;
 
-void build_pyramid( double **luminance, int ImageWidth, int ImageHeight );
-double V1( int x, int y, int level );
+static float ***Pyramid;
+static int   PyramidWidth0;
 
-int div2( const unsigned int n )
+static int div2( const unsigned int n )
 {
   const int q = n/2;
   return(2*q < n ? q + 1 : q);
 }
 
-double pyramid_lookup( int x, int y, int level )
+static float pyramid_lookup( int x, int y, int level )
   /* PRE:  */
 {
   int n, s;
   
   /* Level 0 is a special case, the value is just the image */
   if (level == 0) {
-    if ( (x < 0) || (y < 0) || (x >= ImageWidth) || (y >= ImageHeight) )
+    if ( (x < 0) || (y < 0) || (x >= width) || (y >= height) )
       return(0.0);
     else
-      return(luminance[y][x]);
+      return((*lum)(x,y));
   }
 
   /* Compute the size of the slice */
@@ -58,25 +58,24 @@
   //y = y >> level;
 
   if ( (x < 0) || (y < 0) || (x >= s) || (y >= s) )
-    return(0.0);
+    return(0.0f);
   else
     return(Pyramid[level][y][x]);
 }
 
-void build_pyramid( double **luminance, int image_width, int image_height )
+void build_pyramid()
 {
   int k;
   int x, y;
   int i, j;
-  int width, height;
   int max_dim;
-  int pyramid_height;
-  double sum = 0;
+  int pyramid_width;
+  double sum = 0.f;
   
-  double a = 0.4;
-  double b = 0.25;
-  double c = b - a/2;
-  double w[5];
+  float a = 0.4f;
+  float b = 0.25f;
+  float c = b - a/2.f;
+  float w[5];
 
   /* Compute the "filter kernel" */
   w[0] = c;
@@ -90,50 +89,35 @@
   /* For simplicity, the first level is padded to a square whose side is a */
   /* power of two.                                                         */
 
-  ImageWidth = image_width;
-  ImageHeight = image_height;
-  
   /* Compute the size of the Pyramid array */
-  max_dim = (ImageHeight > ImageWidth ? ImageHeight : ImageWidth);
-  PyramidHeight = (int) floor(log(max_dim - 0.5)/log(2)) + 1;
+  max_dim = (height > width ? height : width);
+  PyramidHeight = (int)floorf(logf(max_dim - 0.5f)/logf(2)) + 1;
 
   /* Compute the dimensions of the first level */
-  width = 1 << (PyramidHeight - 1);
-  PyramidWidth0 = width;
+  pyramid_width = 1 << (PyramidHeight - 1);
+  PyramidWidth0 = pyramid_width;
 
 //  fprintf(stderr, "max_dim %d   height %d\n", max_dim, PyramidHeight);
   
   /* Allocate the outer Pyramid array */
-  Pyramid = (double***) calloc(PyramidHeight, sizeof(double**));
-  if (!Pyramid) {
-    fprintf(stderr, "Unable to allocate pyramid array.\n");
-    exit(1);
-  }
+  Pyramid = new float**[PyramidHeight];
 
   /* Allocate and assign the Pyramid slices */
   k = 0;
   
-  while (width) {
+  while (pyramid_width) {
 
 //    fprintf(stderr, "level %d, width = %d\n", k, width);
     
     /* Allocate the slice */
-    Pyramid[k] = (double**) calloc(width, sizeof(double*));
-    if (!Pyramid[k]) {
-      fprintf(stderr, "Unable to allocate pyramid array.\n");
-      exit(1);
-    }
-    for (y = 0; y < width; y++) {
-      Pyramid[k][y] = (double*) calloc(width, sizeof(double));
-      if (!Pyramid[k][y]) {
-        fprintf(stderr, "Unable to allocate pyramid array.\n");
-        exit(1);
-      }
+    Pyramid[k] = new float*[pyramid_width];
+    for (y = 0; y < pyramid_width; y++) {
+      Pyramid[k][y] = new float[pyramid_width];
     }
 
     /* Compute the values in the slice */
-    for (y = 0; y < width; y++) {
-      for (x = 0; x < width; x++) {
+    for (y = 0; y < pyramid_width; y++) {
+      for (x = 0; x < pyramid_width; x++) {
 
         sum = 0;
         for (i = 0; i < 5; i++) {
@@ -146,7 +130,7 @@
     }
 
     /* compute the width of the next slice */
-    width /= 2;
+    pyramid_width /= 2;
     k++;
   }
 }
@@ -154,27 +138,27 @@
 void clean_pyramid()
 {
   int k=0;
-  int width = PyramidWidth0;
-  while(width)
+  int pyramid_width = PyramidWidth0;
+  while(pyramid_width)
   {
-    for( int y=0 ; y<width ; y++ )
-      free(Pyramid[k][y]);
-    free(Pyramid[k]);
+    for( int y=0 ; y<pyramid_width ; y++ )
+      delete[] Pyramid[k][y];
+    delete[] Pyramid[k];
     k++;
-    width /= 2;
+    pyramid_width /= 2;
   }
-  free(Pyramid);
+  delete[] Pyramid;
 }
 
 #ifndef INTERPOLATED
-double V1( int x, int y, int level )
+float V1( int x, int y, int level )
   /* PRE:  */
 {
   int n, s;
 
   /* Level 0 is a special case, the value is just the image */
   if (level <= 0)
-      return(luminance[y][x]);
+      return((*lum)(x,y));
 
   /* Compute the size of the slice */
   
@@ -184,16 +168,16 @@
   return(Pyramid[level-1][y][x]);
 }
 #else
-double V1( int x, int y, int level )
+float V1( int x, int y, int level )
   /* PRE:  */
 {
   int x0, y0;
   int l, size;
-  double s, t;
+  float s, t;
   
   /* Level 0 is a special case, the value is just the image */
   if (level == 0)
-      return(luminance[y][x]);
+      return((*lum)(x,y));
 
   /* Compute the size of the slice */
   l = 1 << level;
@@ -204,8 +188,8 @@
   x0 = (x0 >= size ? size - 1 : x0);
   y0 = (y0 >= size ? size - 1 : y0);
   
-  s = (double)(x - x0*l)/(double)l;
-  t = (double)(y - y0*l)/(double)l;
+  s = (float)(x - x0*l)/(float)l;
+  t = (float)(y - y0*l)/(float)l;
   
   level--;
 
