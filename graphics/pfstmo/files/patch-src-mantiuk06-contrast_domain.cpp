--- src/mantiuk06/contrast_domain.cpp.orig	2012-04-22 13:14:14.000000000 +0000
+++ src/mantiuk06/contrast_domain.cpp	2014-06-18 15:29:52.298957047 +0000
@@ -74,8 +74,6 @@
 static void matrix_copy(const int n, const float* const a, float* const b);
 static void matrix_multiply_const(const int n, float* const a, const float val);
 static void matrix_divide(const int n, const float* const a, float* const b);
-static float* matrix_alloc(const int size);
-static void matrix_free(float* m);
 static float matrix_DotProduct(const int n, const float* const a, const float* const b);
 static void matrix_zero(const int n, float* const m);
 static void calculate_and_add_divergence(const int rows, const int cols, const float* const Gx, const float* const Gy, float* const divG);
@@ -317,24 +315,6 @@
 }
 
 
-// alloc memory for the float table
-static inline float* matrix_alloc(int size){
-
-  float* m = (float*)malloc(sizeof(float)*size);
-  if(m == NULL){
-    fprintf(stderr, "ERROR: malloc in matrix_alloc() (size:%d)", size);
-    exit(155);
-  }
-
-  return m;
-}
-
-// free memory for matrix
-static inline void matrix_free(float* m){
-  if(m != NULL)
-    free(m);
-}
-
 // multiply vector by vector (each vector should have one dimension equal to 1)
 static inline float matrix_DotProduct(const int n, const float* const a, const float* const b){
   float val = 0;
@@ -382,7 +362,7 @@
 // temp is a temporary matrix of size (cols, rows), assumed to already be allocated
 static void pyramid_calculate_divergence_sum(pyramid_t* pyramid, float* divG_sum)
 {
-  float* temp = matrix_alloc(pyramid->rows*pyramid->cols);
+  float* temp = new float[pyramid->rows*pyramid->cols];
 
   // Find the coarsest pyramid, and the number of pyramid levels
   int levels = 1;
@@ -426,7 +406,7 @@
       pyramid = pyramid->prev;
     }
 
-  matrix_free(temp);
+  delete[] temp;
 }
 
 // calculate scale factors (Cx,Cy) for gradients (Gx,Gy)
@@ -495,20 +475,10 @@
 {
   while (pyramid)
     {
-      if(pyramid->Gx != NULL)
-	{
-	  free(pyramid->Gx);
-	  pyramid->Gx = NULL;
-	}
-      if(pyramid->Gy != NULL)
-	{
-	  free(pyramid->Gy);
-	  pyramid->Gy = NULL;
-	}
+      delete[] pyramid->Gx;
+      delete[] pyramid->Gy;
       pyramid_t* const next = pyramid->next;
-      pyramid->prev = NULL;
-      pyramid->next = NULL;
-      free(pyramid);
+      delete pyramid;
       pyramid = next;
     }			
 }
@@ -523,19 +493,14 @@
 
   while(rows >= PYRAMID_MIN_PIXELS && cols >= PYRAMID_MIN_PIXELS)
     {
-      level = (pyramid_t *) malloc(sizeof(pyramid_t));
-      if(level == NULL)
-	{
-	  fprintf(stderr, "ERROR: malloc in pyramid_alloc() (size:%d)", (int)sizeof(pyramid_t));
-	  exit(155);
-	}
+      level = new pyramid_t;
       memset( level, 0, sizeof(pyramid_t) );
       
       level->rows = rows;
       level->cols = cols;
       const int size = level->rows * level->cols;
-      level->Gx = matrix_alloc(size);
-      level->Gy = matrix_alloc(size);
+      level->Gx = new float[size];
+      level->Gy = new float[size];
       
       level->prev = prev;
       if(prev != NULL)
@@ -598,7 +563,7 @@
 // lum_temp gets overwritten!
 static void pyramid_calculate_gradient(pyramid_t* pyramid, float* lum_temp)
 {
-  float* temp = matrix_alloc((pyramid->rows/2)*(pyramid->cols/2));
+  float* temp = new float[(pyramid->rows/2)*(pyramid->cols/2)];
   float* const temp_saved = temp;
 
   calculate_gradient(pyramid->cols, pyramid->rows, lum_temp, pyramid->Gx, pyramid->Gy);	
@@ -626,7 +591,7 @@
       pyramid = pyramid->next;
   }
 
-  matrix_free(temp_saved);
+  delete[] temp_saved;
 }
 
 
@@ -658,13 +623,13 @@
   const int n = rows*cols;
   const float tol2 = tol*tol;
 	
-  float* const z = matrix_alloc(n);
-  float* const zz = matrix_alloc(n);
-  float* const p = matrix_alloc(n);
-  float* const pp = matrix_alloc(n);
-  float* const r = matrix_alloc(n);
-  float* const rr = matrix_alloc(n);	
-  float* const x_save = matrix_alloc(n);	
+  float* const z = new float[n];
+  float* const zz = new float[n];
+  float* const p = new float[n];
+  float* const pp = new float[n];
+  float* const r = new float[n];
+  float* const rr = new float[n];	
+  float* const x_save = new float[n];	
 	
   const float bnrm2 = matrix_DotProduct(n, b, b);
 	
@@ -799,13 +764,13 @@
     progress_cb(100);
     
   
-  matrix_free(x_save);
-  matrix_free(p);
-  matrix_free(pp);
-  matrix_free(z);
-  matrix_free(zz);
-  matrix_free(r);
-  matrix_free(rr);
+  delete[] x_save;
+  delete[] p;
+  delete[] pp;
+  delete[] z;
+  delete[] zz;
+  delete[] r;
+  delete[] rr;
 }
 
 
@@ -818,10 +783,10 @@
   const int n = rows*cols;
   const float tol2 = tol*tol;
 	
-  float* const x_save = matrix_alloc(n);
-  float* const r = matrix_alloc(n);
-  float* const p = matrix_alloc(n);
-  float* const Ap = matrix_alloc(n);	
+  float* const x_save = new float[n];
+  float* const r = new float[n];
+  float* const p = new float[n];
+  float* const Ap = new float[n];	
 	
   // bnrm2 = ||b||
   const float bnrm2 = matrix_DotProduct(n, b, b);
@@ -943,10 +908,10 @@
   else if (progress_cb != NULL)
     progress_cb(100);
     
-  matrix_free(x_save);
-  matrix_free(p);
-  matrix_free(Ap);
-  matrix_free(r);
+  delete[] x_save;
+  delete[] p;
+  delete[] Ap;
+  delete[] r;
 }
 
 
@@ -1070,7 +1035,7 @@
   pyramid_calculate_scale_factor(pp, pC); // calculate (Cx,Cy)
   pyramid_scale_gradient(pp, pC); // scale small gradients by (Cx,Cy);
 
-  float* b = matrix_alloc(pp->cols * pp->rows);
+  float* b = new float[pp->cols * pp->rows];
   pyramid_calculate_divergence_sum(pp, b); // calculate the sum of divergences (equal to b)
   
   // calculate luminances from gradients
@@ -1079,7 +1044,7 @@
   else
     lincg(pp, pC, b, x, itmax, tol, progress_cb);
   
-  matrix_free(b);
+  delete[] b;
   pyramid_free(pC);
 }
 
@@ -1121,12 +1086,7 @@
     }
   
   // Allocate memory
-  struct hist_data* hist = (struct hist_data*) malloc(sizeof(struct hist_data) * total_pixels);
-  if (hist == NULL)
-    {
-      fprintf(stderr, "ERROR: malloc in contrast_equalization() (size:%d)", (int)sizeof(struct hist_data) * total_pixels);
-      exit(155);
-    }
+  struct hist_data* hist = new hist_data[total_pixels];
     
   // Build histogram info
   l = pp;
@@ -1175,7 +1135,7 @@
     l = l->next;
   }
 
-  free(hist);
+  delete[] hist;
 }
 
 
@@ -1211,10 +1171,10 @@
     }
 	
   pyramid_t* pp = pyramid_allocate(c,r); // create pyramid
-  float* tY = matrix_alloc(n);
+  float* tY = new float[n];
   matrix_copy(n, Y, tY); // copy Y to tY
   pyramid_calculate_gradient(pp,tY); // calculate gradients for pyramid, destroys tY
-  matrix_free(tY);
+  delete[] tY;
   pyramid_transform_to_R(pp); // transform gradients to R
 
   /* Contrast map */
@@ -1228,7 +1188,7 @@
   pyramid_free(pp);
 
   /* Renormalize luminance */
-  float* temp = matrix_alloc(n);
+  float* temp = new float[n];
 	
   matrix_copy(n, Y, temp); // copy Y to temp
   qsort(temp, n, sizeof(float), sort_float); // sort temp in ascending order
@@ -1244,7 +1204,7 @@
   delta = trim - floorf(trim);
   const float l_max = temp[(int)floorf(trim)] * delta + temp[(int)ceilf(trim)] * (1.0f-delta);	
 	
-  matrix_free(temp);
+  delete[] temp;
 	
   const float disp_dyn_range = 2.3f;
 #pragma omp parallel for schedule(static)
