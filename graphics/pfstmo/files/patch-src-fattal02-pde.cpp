--- src/fattal02/pde.cpp.orig	2012-06-21 13:27:13.000000000 +0000
+++ src/fattal02/pde.cpp	2014-06-18 15:29:52.288954426 +0000
@@ -70,15 +70,15 @@
 // precision
 #define EPS 1.0e-12
 
-void linbcg(unsigned long n, float b[], float x[], int itol, float tol,
+static void linbcg(unsigned long n, float b[], float x[], int itol, float tol,
   int itmax, int *iter, float *err);
 
-inline float max( float a, float b )
+static inline float max( float a, float b )
 {
   return a > b ? a : b;
 }
 
-inline float min( float a, float b )
+static inline float min( float a, float b )
 {
   return a < b ? a : b;
 }
@@ -109,7 +109,7 @@
 // Full Multigrid Algorithm for solving partial differential equations
 //////////////////////////////////////////////////////////////////////
 
-void restrict( const pfstmo::Array2D *in, pfstmo::Array2D *out )
+static void restrict( const pfstmo::Array2D *in, pfstmo::Array2D *out )
 {
   const float inRows = in->getRows();
   const float inCols = in->getCols();
@@ -172,7 +172,7 @@
 // }
 
 
-void prolongate( const pfstmo::Array2D *in, pfstmo::Array2D *out )
+static void prolongate( const pfstmo::Array2D *in, pfstmo::Array2D *out )
 {
   float dx = (float)in->getCols() / (float)out->getCols();
   float dy = (float)in->getRows() / (float)out->getRows();
@@ -216,7 +216,7 @@
 }
 
 // to_level<from_level, from_size<to_size
-void prolongate_old( pfstmo::Array2D *F, pfstmo::Array2D *T )
+static void prolongate_old( pfstmo::Array2D *F, pfstmo::Array2D *T )
 {
 //   DEBUG_STR << "prolongate" << endl;
 
@@ -277,7 +277,7 @@
     }
 }
 
-void exact_sollution( pfstmo::Array2D *F, pfstmo::Array2D *U )
+static void exact_sollution( pfstmo::Array2D *F, pfstmo::Array2D *U )
 {
 //   DEBUG_STR << "exact sollution" << endl;
 
@@ -314,13 +314,13 @@
 
 static int rows, cols;
 
-inline int idx( int r, int c )
+static inline int idx( int r, int c )
 {
   return r*cols+c+1;
 }
 
 // smooth u using f at level
-void smooth( pfstmo::Array2D *U, pfstmo::Array2D *F )
+static void smooth( pfstmo::Array2D *U, pfstmo::Array2D *F )
 {
 //   DEBUG_STR << "smooth" << endl;
   
@@ -369,7 +369,7 @@
 //   }
 }
 
-void calculate_defect( pfstmo::Array2D *D, pfstmo::Array2D *U, pfstmo::Array2D *F )
+static void calculate_defect( pfstmo::Array2D *D, pfstmo::Array2D *U, pfstmo::Array2D *F )
 {
 //   DEBUG_STR << "calculate defect" << endl;
 
@@ -395,7 +395,7 @@
   
 }
 
-void add_correction( pfstmo::Array2D *U, pfstmo::Array2D *C )
+static void add_correction( pfstmo::Array2D *U, pfstmo::Array2D *C )
 {
 //   DEBUG_STR << "add_correction" << endl;
 
@@ -646,7 +646,7 @@
 
 //#define EPS 1.0e-14
 
-void asolve(unsigned long n, float b[], float x[], int itrnsp)
+static void asolve(float b[], float x[])
 {
     for( int r = 0; r < rows; r++ )
       for( int c = 0; c < cols; c++ ) {
@@ -654,7 +654,7 @@
       }
 }
 
-void atimes(unsigned long n, float x[], float res[], int itrnsp)
+static void atimes(float x[], float res[])
 {
   for( int r = 1; r < rows-1; r++ )
     for( int c = 1; c < cols-1; c++ ) {
@@ -682,7 +682,7 @@
     - 2*x[idx(rows-1,cols-1)];  
 }
 
-float snrm(unsigned long n, float sx[], int itol)
+static float snrm(unsigned long n, float sx[], int itol)
 {
 	unsigned long i,isamax;
 	float ans;
@@ -704,7 +704,7 @@
  * Biconjugate Gradient Method
  * from Numerical Recipes in C
  */
-void linbcg(unsigned long n, float b[], float x[], int itol, float tol,	int itmax, int *iter, float *err)
+static void linbcg(unsigned long n, float b[], float x[], int itol, float tol,	int itmax, int *iter, float *err)
 {	
 	unsigned long j;
 	float ak,akden,bk,bkden,bknum,bnrm,dxnrm,xnrm,zm1nrm,znrm;
@@ -718,30 +718,30 @@
 	zz=new float[n+1];
 
 	*iter=0;
-	atimes(n,x,r,0);
+	atimes(x,r);
 	for (j=1;j<=n;j++) {
 		r[j]=b[j]-r[j];
 		rr[j]=r[j];
 	}
-	atimes(n,r,rr,0);       // minimum residual
+	atimes(r,rr);       // minimum residual
         znrm=1.0;
 	if (itol == 1) bnrm=snrm(n,b,itol);
 	else if (itol == 2) {
-		asolve(n,b,z,0);
+		asolve(b,z);
 		bnrm=snrm(n,z,itol);
 	}
 	else if (itol == 3 || itol == 4) {
-		asolve(n,b,z,0);
+		asolve(b,z);
 		bnrm=snrm(n,z,itol);
-		asolve(n,r,z,0);
+		asolve(r,z);
 		znrm=snrm(n,z,itol);
 	} else printf("illegal itol in linbcg");
-	asolve(n,r,z,0);        
+	asolve(r,z);        
 
 	while (*iter <= itmax) {
 		++(*iter);
 		zm1nrm=znrm;
-		asolve(n,rr,zz,1);
+		asolve(rr,zz);
 		for (bknum=0.0,j=1;j<=n;j++) bknum += z[j]*rr[j];
 		if (*iter == 1) {
 			for (j=1;j<=n;j++) {
@@ -757,16 +757,16 @@
 			}
 		}                
 		bkden=bknum;
-		atimes(n,p,z,0);
+		atimes(p,z);
 		for (akden=0.0,j=1;j<=n;j++) akden += z[j]*pp[j];
 		ak=bknum/akden;
-		atimes(n,pp,zz,1);
+		atimes(pp,zz);
 		for (j=1;j<=n;j++) {
 			x[j] += ak*p[j];
 			r[j] -= ak*z[j];
 			rr[j] -= ak*zz[j];
 		}
-		asolve(n,r,z,0);
+		asolve(r,z);
 		if (itol == 1 || itol == 2) {
 			znrm=1.0;
 			*err=snrm(n,r,itol)/bnrm;
