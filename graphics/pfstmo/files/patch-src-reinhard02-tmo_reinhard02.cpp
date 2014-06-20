--- src/reinhard02/tmo_reinhard02.cpp.orig	2009-04-15 11:49:32.000000000 +0000
+++ src/reinhard02/tmo_reinhard02.cpp	2014-06-18 15:29:52.328951402 +0000
@@ -17,11 +17,12 @@
 
 #include <config.h>
 
+#include <memory>
 #include <stdlib.h>
 #include <stdio.h>
 #include <math.h>
 
-#include "pfstmo.h"
+#include <pfstmo.h>
 
 #ifdef HAVE_ZFFT
 #include <fft.h>
@@ -30,53 +31,44 @@
 #define APPROXIMATE
 #endif
 
-//--- from defines.h
-typedef struct {
-  int     xmax, ymax;     /* image dimensions */
-} CVTS;
 
-typedef double  COLOR[3];       /* red, green, blue (or X,Y,Z) */
-//--- end of defines.h
-
-
-static int       width, height, scale;
-static COLOR   **image;
-static double ***convolved_image;
-static double    sigma_0, sigma_1;
-double         **luminance;
-
-static double    k                = 1. / (2. * 1.4142136);
-static double    key              = 0.18;
-static double    threshold        = 0.05;
-static double    phi              = 8.;
-static double    white            = 1e20;
-static int       scale_low        = 1;
-static int       scale_high       = 43;  // 1.6^8 = 43
-static int       range            = 8;
-static int       use_scales       = 0;
-static int       use_border       = 0;
-static CVTS      cvts             = {0, 0};
+static int                      scale;
+static float                    sigma_0, sigma_1;
+static pfstmo::Array2D          *img = 0;
+pfstmo::Array2D                 *lum = 0;
+int                             width, height;
+
+static float    k               = 1.f / (2.f * 1.4142136f);
+static float    key             = 0.18f;
+static float    threshold       = 0.05f;
+static float    phi             = 8.f;
+static float    white           = 1e20f;
+static int      scale_low       = 1;
+static int      scale_high      = 43;  // 1.6^8 = 43
+static int      range           = 8;
+static int      use_scales      = 0;
+static float    border          = 0.f;
 
 static bool temporal_coherent;
 
 #ifdef APPROXIMATE
 extern int PyramidHeight; // set by build_pyramid, defines actual pyramid size
-extern double V1 (int x, int y, int level);
-extern void build_pyramid (double **luminance, int image_width, int image_height);
-extern void clean_pyramid ();
+extern float V1(int x, int y, int level);
+extern void build_pyramid();
+extern void clean_pyramid();
 #else
-
+static double ***convolved_image;
 static zomplex **filter_fft;
 static zomplex  *image_fft, *coeff;
 
-#define V1(x,y,i)        (convolved_image[i][x][y])
+#define V1(x,y,i)       ((float)convolved_image[i][x][y])
 
 #endif
 
-#define SIGMA_I(i)       (sigma_0 + ((double)i/(double)range)*(sigma_1 - sigma_0))
-#define S_I(i)           (exp (SIGMA_I(i)))
-#define V2(x,y,i)        (V1(x,y,i+1))
-#define ACTIVITY(x,y,i)  ((V1(x,y,i) - V2(x,y,i)) / (((key * pow (2., phi))/(S_I(i)*S_I(i))) + V1(x,y,i)))
+#define SIGMA_I(i)      (sigma_0 + ((float)i/(float)range)*(sigma_1 - sigma_0))
+#define S_I(i)          (expf(SIGMA_I(i)))
+#define V2(x,y,i)       (V1(x,y,i+1))
+#define ACTIVITY(x,y,i) ((V1(x,y,i) - V2(x,y,i)) / (((key * powf(2.f, phi))/(S_I(i)*S_I(i))) + V1(x,y,i)))
 
 
 
@@ -119,32 +111,32 @@
 };
 
 
-static TemporalSmoothVariable<double> avg_luminance, max_luminance;
+static TemporalSmoothVariable<float> avg_luminance, max_luminance;
 
 
 /*
  * Kaiser-Bessel stuff
  */
 
-static double   alpha = 2.;         /* Kaiser-Bessel window parameter   */
-static double   bbeta;              /* Will contain bessel (PI * alpha) */
+static float   alpha = 2.f;        /* Kaiser-Bessel window parameter   */
+static float   bbeta;              /* Will contain bessel (PI * alpha) */
 
 /*
  * Modified zeroeth order bessel function of the first kind
  */
 
-double bessel (double x)
+static float bessel (float x)
 {
-  const double f = 1e-9;
+  const float f = 1e-9f;
   int          n = 1;
-  double       s = 1.;
-  double       d = 1.;
+  float       s = 1.f;
+  float       d = 1.f;
 
-  double t;
+  float t;
 
   while (d > f * s)
   {
-    t = x / (2. * n);
+    t = x / (2.f * n);
     n++;
     d *= t * t;
     s += d;
@@ -156,7 +148,7 @@
  * Initialiser for Kaiser-Bessel computations
  */
 
-void compute_bessel ()
+static void compute_bessel ()
 {
   bbeta = bessel (M_PI * alpha);
 }
@@ -166,12 +158,12 @@
  * Window length M = min (width, height) / 2
  */
 
-double kaiserbessel (double x, double y, double M)
+static float kaiserbessel (float x, float y, float M)
 {
-  double d = 1. - ((x*x + y*y) / (M * M));
-  if (d <= 0.)
-    return 0.;
-  return bessel (M_PI * alpha * sqrt (d)) / bbeta;
+  float d = 1.f - ((x*x + y*y) / (M * M));
+  if (d <= 0.f)
+    return 0.f;
+  return bessel(M_PI * alpha * sqrtf(d)) / bbeta;
 }
 
 
@@ -180,57 +172,57 @@
  */
 #ifdef HAVE_ZFFT
 
-void initialise_fft (int width, int height)
+static void initialise_fft (int width, int height)
 {
   coeff = zfft2di (width, height, NULL);
 }
 
-void compute_fft (zomplex *array, int width, int height)
+static void compute_fft (zomplex *array, int width, int height)
 {
   zfft2d (-1, width, height, array, width, coeff);
 }
 
-void compute_inverse_fft (zomplex *array, int width, int height)
+static void compute_inverse_fft (zomplex *array, int width, int height)
 {
   zfft2d (1, width, height, array, width, coeff);
 }
 
 
 // Compute Gaussian blurred images
-void gaussian_filter (zomplex *filter, double scale, double k )
+static void gaussian_filter (zomplex *filter, double scale, double k )
 {
   int    x, y;
   double x1, y1, s;
   double a = 1. / (k * scale);
   double c = 1. / 4.;
 
-  for (y = 0; y < cvts.ymax; y++)
+  for (y = 0; y < height; y++)
   {
-    y1 = (y >= cvts.ymax / 2) ? y - cvts.ymax : y;
+    y1 = (y >= height / 2) ? y - height : y;
     s  = erf (a * (y1 - .5)) - erf (a * (y1 + .5));
-    for (x = 0; x < cvts.xmax; x++)
+    for (x = 0; x < width; x++)
     {
-      x1 = (x >= cvts.xmax / 2) ? x - cvts.xmax : x;
-      filter[y*cvts.xmax + x].re = s * (erf (a * (x1 - .5)) - erf (a * (x1 + .5))) * c;
-      filter[y*cvts.xmax + x].im = 0.;
+      x1 = (x >= width / 2) ? x - width : x;
+      filter[y*width + x].re = s * (erf (a * (x1 - .5)) - erf (a * (x1 + .5))) * c;
+      filter[y*width + x].im = 0.;
     }
   }
 }
 
-void build_gaussian_fft ()
+static void build_gaussian_fft ()
 {
-  int    i;
-  double length    = cvts.xmax * cvts.ymax;
-  double fft_scale = 1. / sqrt (length);
-  filter_fft      = (zomplex**) calloc (range, sizeof (zomplex*));
+  int i;
+  int length = width * height;
+  double fft_scale = 1. / sqrt((double)length);
+  filter_fft = new zomplex*[range];
 
   for (scale = 0; scale < range; scale++)
   {
     fprintf (stderr, "Computing FFT of Gaussian at scale %i (size %i x %i)%c", 
-	     scale, cvts.xmax, cvts.ymax, (char)13);
-    filter_fft[scale] = (zomplex*) calloc (length, sizeof (zomplex));
+	     scale, width, height, (char)13);
+    filter_fft[scale] = new zomplex[length];
     gaussian_filter (filter_fft[scale], S_I(scale), k);
-    compute_fft     (filter_fft[scale], cvts.xmax, cvts.ymax);
+    compute_fft     (filter_fft[scale], width, height);
     for (i = 0; i < length; i++)
     {
       filter_fft[scale][i].re *= fft_scale;
@@ -240,20 +232,20 @@
   fprintf (stderr, "\n");
 }
 
-void build_image_fft ()
+static void build_image_fft ()
 {
-  int    i, x, y;
-  double length    = cvts.xmax * cvts.ymax;
-  double fft_scale = 1. / sqrt (length);
+  int i, x, y;
+  int length = width * height;
+  double fft_scale = 1. / sqrt((double)length);
 
   fprintf (stderr, "Computing image FFT\n");
-  image_fft = (zomplex*) calloc (length, sizeof (zomplex));
+  image_fft = new zomplex[length];
 
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
-      image_fft[y*cvts.xmax + x].re = luminance[y][x];
+  for (y = 0; y < height; y++)
+    for (x = 0; x < width; x++)
+      image_fft[y*width + x].re = (*lum)(x,y);
 
-  compute_fft (image_fft, cvts.xmax, cvts.ymax);
+  compute_fft (image_fft, width, height);
   for (i = 0; i < length; i++)
   {
     image_fft[i].re *= fft_scale;
@@ -261,47 +253,61 @@
   }
 }
 
-void convolve_filter (int scale, zomplex *convolution_fft)
+static void convolve_filter (int scale, zomplex *convolution_fft)
 {
   int i, x, y;
 
-  for (i = 0; i < cvts.xmax * cvts.ymax; i++)
+  for (i = 0; i < width * height; i++)
   {
     convolution_fft[i].re = image_fft[i].re * filter_fft[scale][i].re -
                             image_fft[i].im * filter_fft[scale][i].im;
     convolution_fft[i].im = image_fft[i].re * filter_fft[scale][i].im +
                             image_fft[i].im * filter_fft[scale][i].re;
   }
-  compute_inverse_fft (convolution_fft, cvts.xmax, cvts.ymax);
+  compute_inverse_fft (convolution_fft, width, height);
   i = 0;
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
+  for (y = 0; y < height; y++)
+    for (x = 0; x < width; x++)
       convolved_image[scale][x][y] = convolution_fft[i++].re;
 }
 
-void compute_fourier_convolution ()
+static void compute_fourier_convolution ()
 {
   int x;
   zomplex *convolution_fft;
 
-  initialise_fft     (cvts.xmax, cvts.ymax);
+  initialise_fft     (width, height);
   build_image_fft    ();
   build_gaussian_fft ();
-  convolved_image =  (double ***) malloc (range * sizeof (double **));
+  convolved_image =  new double**[range];
 
-  convolution_fft =  (zomplex *) calloc (cvts.xmax * cvts.ymax, sizeof (zomplex));
+  convolution_fft =  new zomplex[width * height];
   for (scale = 0; scale < range; scale++)
   {
     fprintf (stderr, "Computing convolved image at scale %i%c", scale, (char)13);
-    convolved_image[scale] = (double **) malloc (cvts.xmax * sizeof (double *));
-    for (x = 0; x < cvts.xmax; x++)
-      convolved_image[scale][x] = (double *) malloc (cvts.ymax * sizeof (double));
+    convolved_image[scale] = new double*[width];
+    for (x = 0; x < width; x++)
+      convolved_image[scale][x] = new double[height];
     convolve_filter (scale, convolution_fft);
-    free (filter_fft[scale]);
+    delete[] filter_fft[scale];
   }
+  delete[] filter_fft;
   fprintf (stderr, "\n");
-  free (convolution_fft);
-  free (image_fft);
+  delete[] convolution_fft;
+  delete[] image_fft;
+}
+
+static void clean_convolved_image()
+{
+  for (scale = 0; scale < range; scale++)
+  {
+    for (x = 0; x < width; x++)
+    {
+      delete[] convolved_image[scale][x];
+    }
+    delete[] convolved_image[scale];
+  }
+  delete[] convolved_image;
 }
 
 #endif // #ifdef HAVE_ZFFT
@@ -312,188 +318,141 @@
  * Tonemapping routines
  */
 
-double get_maxvalue ()
+static void tonemap()
 {
-  double max = 0.;
-  int    x, y;
-
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
-      max = (max < image[y][x][0]) ? image[y][x][0] : max;
-  return max;
-}
-
-void tonemap_image ()
-{
-  double Lmax2;
-  int    x, y;
-  int    scale, prefscale;
-
-  if (white < 1e20)
-    Lmax2 = white * white;
-  else
+  for (int y = 0; y<height; y++)
   {
-    if( temporal_coherent ) {
-      max_luminance.set( get_maxvalue() );
-      Lmax2 = max_luminance.get();
-    } else Lmax2  = get_maxvalue();
-    Lmax2 *= Lmax2;
-  }
-
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
+    for (int x = 0; x<width; x++)
     {
-      if (use_scales)
+      int prefscale = range-1;
+      for (int scale = 0; scale<range-1; scale++)
       {
-	prefscale = range - 1;
-	for (scale = 0; scale < range - 1; scale++)
-	  if ( scale >= PyramidHeight || fabs (ACTIVITY(x,y,scale)) > threshold)
+	  if (scale>=PyramidHeight || fabsf(ACTIVITY(x,y,scale))>threshold)
 	  {
 	    prefscale = scale;
 	    break;
 	  }
-	image[y][x][0] /= 1. + V1(x,y,prefscale);
       }
-      else
-	image[y][x][0] = image[y][x][0] * (1. + (image[y][x][0] / Lmax2)) / (1. + image[y][x][0]);
-      // image[y][x][0] /= (1. + image[y][x][0]);
+      (*img)(x,y) = (*lum)(x,y)/(1.f+V1(x,y,prefscale));
     }
+  }
 }
 
-/*
- * Miscellaneous functions
- */
-
-void clamp_image ()
+static float get_maxvalue()
 {
-  int x, y;
-
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
-    {
-      image[y][x][0] = (image[y][x][0] > 1.) ? 1. : image[y][x][0];
-      image[y][x][1] = (image[y][x][1] > 1.) ? 1. : image[y][x][1];
-      image[y][x][2] = (image[y][x][2] > 1.) ? 1. : image[y][x][2];
-    }
+  float max = 0.f;
+  int   x, y;
+  for (int i = width*height; i--; )
+  {
+    float l = (*img)(i);
+    if (max<l) max = l;
+  }
+  return max;
 }
 
-double log_average ()
+static void tonecompress()
 {
-  int    x, y;
-  double sum = 0.;
-
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
-      sum += log (0.00001 + luminance[y][x]);
-  return exp (sum / (double)(cvts.xmax * cvts.ymax));
-}
-
-void scale_to_midtone ()
-{
-  int    x, y, u, v, d;
-  double factor;
-  double scale_factor;
-  double low_tone    = key / 3.;
-  int    border_size = (cvts.xmax < cvts.ymax) ? int(cvts.xmax / 5.) : int(cvts.ymax / 5.);
-  int    hw          = cvts.xmax >> 1;
-  int    hh          = cvts.ymax >> 1;
-
-  double avg;
-  if( temporal_coherent ) {
-    avg_luminance.set( log_average() );
-    avg = avg_luminance.get();
-  } else avg = log_average();
-  
-  scale_factor = 1.0 / avg;
-  for (y = 0; y < cvts.ymax; y++)
-    for (x = 0; x < cvts.xmax; x++)
+  float Lmax2;
+  if (white<1e20f)
+  {
+    Lmax2 = white;
+  }
+  else
+  {
+    if (temporal_coherent)
     {
-      if (use_border)
-      {
-	u              = (x > hw) ? cvts.xmax - x : x;
-	v              = (y > hh) ? cvts.ymax - y : y;
-	d              = (u < v) ? u : v;	
-	factor         = (d < border_size) ? (key - low_tone) * 
-	                  kaiserbessel (border_size - d, 0, border_size) + 
-                          low_tone : key;
-      }
-      else
-	factor         = key;
-      image[y][x][0]  *= scale_factor * factor;
-      luminance[y][x] *= scale_factor * factor;
+      max_luminance.set(get_maxvalue());
+      Lmax2 = max_luminance.get();
     }
-}
-
-void copy_luminance ()
-{
-  int x, y;
-
-  for (x = 0; x < cvts.xmax; x++)
-    for (y = 0; y < cvts.ymax; y++)
-      luminance[y][x] = image[y][x][0];
+    else
+    {
+      Lmax2  = get_maxvalue();
+    }
+  }
+  Lmax2 *= Lmax2;
+  for (int i = width*height; i--; )
+  {
+    (*img)(i) = (*lum)(i)*(1.f+(*lum)(i)/Lmax2)/(1.f+(*lum)(i));
+  }
 }
 
 /*
- * Memory allocation
+ * Miscellaneous functions
  */
-void allocate_memory ()
-{
-  int y;
 
-  luminance = (double **) malloc (cvts.ymax * sizeof (double *));
-  image     = (COLOR **) malloc (cvts.ymax * sizeof (COLOR *));
-  for (y = 0; y < cvts.ymax; y++)
+static float log_average()
+{
+  double sum = 0.;
+  int s = width*height;
+  for (int i = s; i--; )
   {
-    luminance[y] = (double *) malloc (cvts.xmax * sizeof (double));
-    image[y]     = (COLOR *) malloc (cvts.xmax * sizeof (COLOR));
+    sum += log(0.00001+(*lum)(i));
   }
+  return expf((float)sum/(float)s);
 }
 
-void deallocate_memory ()
+static void scale_to_midtone()
 {
-  int y;
+  float avg, scale_factor;
+  int   border_size = (int)(((width<height) ? width : height)*border);
 
-  for (y = 0; y < cvts.ymax; y++)
+  avg = log_average();
+  if (temporal_coherent)
   {
-    free(luminance[y]);
-    free(image[y]);
+    avg_luminance.set(avg);
+    avg = avg_luminance.get();
   }
-  free( luminance );
-  free( image );
-}
-
-
-void dynamic_range ()
-{
-  int x, y;
-  double minval =  1e20;
-  double maxval = -1e20;
-
-  for (x = 0; x < cvts.xmax; x++)
-    for (y = 0; y < cvts.ymax; y++)
+  
+  scale_factor = key / avg;
+  for (int i = width*height; i--; )
+  {
+    (*lum)(i) *= scale_factor;
+  }
+  if (border_size)
+  {
+    int hw = width >> 1;
+    int hh = height >> 1;
+    for (int y = 0; y < height; y++)
     {
-      if ((luminance[y][x] < minval) &&
-	  (luminance[y][x] > 0.0))
-	minval = luminance[y][x];
-      if (luminance[y][x] > maxval)
-	maxval = luminance[y][x];
+      int v = (y > hh) ? height - y : y;
+      for (int x = 0; x < width; x++)
+      {
+	int u = (x > hw) ? width - x : x;
+	int d = (u < v) ? u : v;	
+        if (d < border_size) 
+          (*lum)(x,y) *= 
+            (2.f * kaiserbessel(border_size - d, 0, border_size) + 1.f) / 3.f;
+      }
     }
-  fprintf (stderr, "\tRange of values  = %9.8f - %9.8f\n", minval, maxval);
-  fprintf (stderr, "\tDynamic range    = %i:1\n", (int)(maxval/minval));
+  }
 }
 
-void print_parameter_settings ()
+static void dynamic_range()
 {
-  fprintf (stderr, "\tImage size       = %i %i\n", cvts.xmax, cvts.ymax);
-  fprintf (stderr, "\tLowest scale     = %i pixels\t\t(-low <integer>)\n", scale_low);
-  fprintf (stderr, "\tHighest scale    = %i pixels\t\t(-high <integer>)\n", scale_high);
-  fprintf (stderr, "\tNumber of scales = %i\t\t\t(-num <integer>)\n", range);
-  fprintf (stderr, "\tScale spacing    = %f\n", S_I(1) / S_I(0));
-  fprintf (stderr, "\tKey value        = %f\t\t(-key <float>)\n", key);
-  fprintf (stderr, "\tWhite value      = %f\t\t(-white <float>)\n", white);
-  fprintf (stderr, "\tPhi              = %f\t\t(-phi <float>)\n", phi);
-  fprintf (stderr, "\tThreshold        = %f\t\t(-threshold <float>)\n", threshold);
-  dynamic_range ();
+  float min =  1e20f;
+  float max = -1e20f;
+  for (int i = width*height; i--; )
+  {
+    float l = (*lum)(i);
+    if (min>l && l>0.f) min = l;
+    if (max<l) max = l;
+  }
+  fprintf(stderr, "\tRange of values  = %9.8f - %9.8f\n", min, max);
+  fprintf(stderr, "\tDynamic range    = %i:1\n", (int)(max/min));
+}
+
+static void print_parameter_settings()
+{
+  fprintf(stderr, "\tImage size       = %i %i\n", width, height);
+  fprintf(stderr, "\tLowest scale     = %i pixels\t\t(-low <integer>)\n", scale_low);
+  fprintf(stderr, "\tHighest scale    = %i pixels\t\t(-high <integer>)\n", scale_high);
+  fprintf(stderr, "\tNumber of scales = %i\t\t\t(-num <integer>)\n", range);
+  fprintf(stderr, "\tScale spacing    = %f\n", S_I(1) / S_I(0));
+  fprintf(stderr, "\tKey value        = %f\t\t(-key <float>)\n", key);
+  fprintf(stderr, "\tWhite value      = %f\t\t(-white <float>)\n", white);
+  fprintf(stderr, "\tPhi              = %f\t\t(-phi <float>)\n", phi);
+  fprintf(stderr, "\tThreshold        = %f\t\t(-threshold <float>)\n", threshold);
+  dynamic_range();
 }
 
 /*
@@ -507,16 +466,15 @@
  * @param num number of scales to use in computation (default: 8)
  * @param low size in pixels of smallest scale (should be kept at 1)
  * @param high size in pixels of largest scale (default 1.6^8 = 43)
+ * @param temporal_coherent tone mapping is time coherent for video sequences
+ * @param border relative width of image area scaled to midtone separately (default: 0 - use key for whole image)
  */
 void tmo_reinhard02(
-  unsigned int width, unsigned int height,
-  const float *nY, float *nL, 
+  const pfstmo::Array2D *Y, pfstmo::Array2D *L, 
   bool use_scales, float key, float phi, 
-  int num, int low, int high, bool temporal_coherent )
+  int num, int low, int high, bool temporal_coherent, float border)
 {
-  const pfstmo::Array2D* Y = new pfstmo::Array2D(width, height, const_cast<float*>(nY));
-  pfstmo::Array2D* L = new pfstmo::Array2D(width, height, nL);
-
+  std::auto_ptr<pfstmo::Array2D> l(0);
   int x,y;
 
   ::key = key;
@@ -526,45 +484,45 @@
   ::scale_high = high;
   ::use_scales = (use_scales) ? 1 : 0;
   ::temporal_coherent = temporal_coherent;
+  ::border = border;
 
-  cvts.xmax = Y->getCols();
-  cvts.ymax = Y->getRows();
+  width = Y->getCols();
+  height = Y->getRows();
 
-  sigma_0      = log (scale_low);
-  sigma_1      = log (scale_high);
+  sigma_0 = logf(scale_low);
+  sigma_1 = logf(scale_high);
 
   compute_bessel();
-  allocate_memory ();
 
-  // reading image
-  for( y=0 ; y<cvts.ymax ; y++ )
-    for( x=0 ; x<cvts.xmax ; x++ )
-      image[y][x][0] = (*Y)(x,y);
+  img = lum = L;
+  if (use_scales)
+  {
+    l.reset(new pfstmo::Array2D(width,height));
+    lum = l.get();
+  }
+  copyArray(Y,lum);
 
-  copy_luminance();
   scale_to_midtone();
 
-  if( use_scales )
+  if (use_scales)
   {
 #ifdef APPROXIMATE
-    build_pyramid(luminance, cvts.xmax, cvts.ymax);
+    build_pyramid();
 #else
     compute_fourier_convolution();
 #endif
+    tonemap();
+  }
+  else
+  {
+    tonecompress();
   }
-
-  tonemap_image();
-
-  // saving image
-  for( y=0 ; y<cvts.ymax ; y++ )
-    for( x=0 ; x<cvts.xmax ; x++ )
-      (*L)(x,y) = image[y][x][0];
 
 //  print_parameter_settings();
 
-  deallocate_memory();
+#ifdef APPROXIMATE
   clean_pyramid();
-
-  delete L;
-  delete Y;
+#else
+  clean_convolved_image();
+#endif
 }
