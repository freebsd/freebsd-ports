--- src/robertson02.cpp.orig	Thu Mar 16 12:22:46 2006
+++ src/robertson02.cpp	Thu Jun 21 14:34:34 2007
@@ -50,7 +50,7 @@
 float normalizeI( float* I, int M );
 
 
-void robertson02_applyResponse( pfs::Array2D* xj, const ExposureList &imgs, 
+int robertson02_applyResponse( pfs::Array2D* xj, const ExposureList &imgs, 
   const float* I, const float* w, int M )
 {
   // number of exposures
@@ -59,6 +59,58 @@
   // frame size
   int width = xj->getCols();
   int height = xj->getRows();
+
+  // number of saturated pixels
+  int saturated_pixels = 0;
+
+  // --- anti saturation: calculate trusted camera output range
+  int minM = 0;
+  for( int m=0 ; m<M ; m++ )
+    if( w[m]>0 )
+    {
+      minM = m;
+      break;
+    }
+  int maxM = M-1;
+  for( int m=M-1 ; m>=0 ; m-- )
+    if( w[m]>0 )
+    {
+      maxM = m;
+      break;
+    }
+  
+  // --- anti ghosting: for each image i, find images with
+  // the immediately higher and lower exposure times
+  int* i_lower = new int[N];
+  int* i_upper = new int[N];
+  for( int i=0 ; i<N ; i++ )
+  {
+    i_lower[i]=-1;
+    i_upper[i]=-1;
+    float ti = imgs[i].ti;
+    float ti_upper = imgs[0].ti;
+    float ti_lower = imgs[0].ti;
+
+    for( int j=0 ; j<N ; j++ )
+      if( i!=j )
+      {
+        if( imgs[j].ti>ti && imgs[j].ti<ti_upper )
+        {
+          ti_upper=imgs[j].ti;
+          i_upper[i]=j;
+        }
+        if( imgs[j].ti<ti && imgs[j].ti>ti_lower )
+        {
+          ti_lower=imgs[j].ti;
+          i_lower[i]=j;
+        }
+      }
+    if( i_lower[i]==-1 )
+      i_lower[i]=i;
+    if( i_upper[i]==-1 )
+      i_upper[i]=i;
+  }
+  
   
   // all pixels
   for( int j=0 ; j<width*height ; j++ )
@@ -66,36 +118,64 @@
     // all exposures for each pixel
     float sum = 0.0f;
     float div = 0.0f;
+
+    float maxti = -1e6f;
+    float minti = +1e6f;
+    
     for( int i=0 ; i<N ; i++ )
     {
       int m = (int) (*imgs[i].yi)(j);
       float ti = imgs[i].ti;
+
+      // --- anti saturation: observe minimum exposure time at which
+      // saturated value is present, and maximum exp time at which
+      // black value is present
+      if( m>maxM )
+        minti = fminf(minti,ti);
+      if( m<minM )
+        maxti = fmaxf(maxti,ti);
+      
+      // --- anti ghosting: monotonous increase in time should result
+      // in monotonous increase in intensity; make forward and
+      // backward check, ignore value if condition not satisfied
+      int m_lower = (int) (*imgs[i_lower[i]].yi)(j);
+      int m_upper = (int) (*imgs[i_upper[i]].yi)(j);
+      if( m_lower>m || m_upper<m)
+        continue;
+      
       sum += w[m] * ti * I[m];
       div += w[m] * ti * ti;
     }
 
-    // This part does not work so well
-//     if( sum < 1e-4 ) {
-//       // If there is not enough information to restore luminance
-//       // (saturated pixels), do not use weighting function
-//       for( int i=0 ; i<N ; i++ )
-//       {
-//         int m = (int) (*imgs[i].yi)(j);
-//         float ti = imgs[i].ti;
-//         sum += ti * I[m];
-//         div += ti * ti;
-//       }
-//     }
-    
+    // --- anti saturation: if a meaningful representation of pixel
+    // was not found, replace it with information from observed data
+    if( div==0.0f )
+      saturated_pixels++;
+    if( div==0.0f && maxti>-1e6f )
+    {
+      sum = I[minM];
+      div = maxti;
+    }
+    if( div==0.0f && minti<+1e6f )
+    {
+      sum = I[maxM];
+      div = minti;
+    }
+      
     if( div!=0.0f )
       (*xj)(j) = sum/div;
     else
       (*xj)(j) = 0.0f;
   }
+
+  delete[] i_lower;
+  delete[] i_upper;
+  
+  return saturated_pixels;
 }
 
 
-void robertson02_getResponse( pfs::Array2D* xj, const ExposureList &imgs,
+int robertson02_getResponse( pfs::Array2D* xj, const ExposureList &imgs,
   float* I, const float* w, int M )
 {
   // number of exposures
@@ -105,6 +185,9 @@
   int width = imgs[0].yi->getCols();
   int height = imgs[0].yi->getRows();
 
+  // number of saturated pixels
+  int saturated_pixels = 0;
+
   // indexes
   int i,j,m;
   
@@ -160,7 +243,7 @@
     float middle_response = normalizeI( I, M );
 
     // 3. Apply new response
-    robertson02_applyResponse( xj, imgs, I, w, M );
+    saturated_pixels = robertson02_applyResponse( xj, imgs, I, w, M );
 
     // 4. Check stopping condition
     float delta = 0.0f;
@@ -198,6 +281,8 @@
   delete[] Ip;
   delete[] cardEm;
   delete[] sum;
+  
+  return saturated_pixels;
 }
 
 
