
$FreeBSD$

--- lib/psy.c.orig	Mon Aug 13 03:36:57 2001
+++ lib/psy.c	Tue Aug 28 01:47:19 2001
@@ -594,95 +594,11 @@
   
 }
 
-static void bark_noise_pointmp(int n,const long *b,
-                               const float *f,
-                               float *noise,
-                               const int fixed){
-  long i,hi=0,lo=0,hif=0,lof=0;
-  double xa=0,xb=0;
-  double ya=0,yb=0;
-  double x2a=0,x2b=0;
-  double y2a=0,y2b=0;
-  double xya=0,xyb=0; 
-  double na=0,nb=0;
-  
-  for(i=0;i<n;i++){
-    if(hi<n){
-      /* find new lo/hi */
-      int bi=b[i]>>16;
-      for(;hi<bi;hi++){
-        double bin=(f[hi]<-140.f?0.:f[hi]+140.);
-        double nn= bin*bin;
-        na  += nn;
-        xa  += hi*nn;
-        ya  += bin*nn;
-        x2a += hi*hi*nn;
-        y2a += bin*bin*nn;
-        xya += hi*bin*nn;
-      }
-      bi=b[i]&0xffff;
-      for(;lo<bi;lo++){
-        double bin=(f[lo]<-140.f?0.:f[lo]+140.);
-        double nn= bin*bin;
-        na  -= nn;
-        xa  -= lo*nn;
-        ya  -= bin*nn;
-        x2a -= lo*lo*nn;
-        y2a -= bin*bin*nn;
-        xya -= lo*bin*nn;
-      }
-    }
-
-    if(hif<n && fixed>0){
-      int bi=i+fixed/2;
-      if(bi>n)bi=n;
-      for(;hif<bi;hif++){
-        double bin=(f[hif]<-140.f?0.:f[hif]+140.);
-        double nn= bin*bin;
-        nb  += nn;
-        xb  += hif*nn;
-        yb  += bin*nn;
-        x2b += hif*hif*nn;
-        y2b += bin*bin*nn;
-        xyb += hif*bin*nn;
-      }
-      bi=i-(fixed+1)/2;
-      if(bi<0)bi=0;
-      for(;lof<bi;lof++){
-        double bin=(f[lof]<-140.f?0.:f[lof]+140.);
-        double nn= bin*bin;
-        nb  -= nn;
-        xb  -= lof*nn;
-        yb  -= bin*nn;
-        x2b -= lof*lof*nn;
-        y2b -= bin*bin*nn;
-        xyb -= lof*bin*nn;
-      }
-    }
-
-    {    
-      double denom=1./(na*x2a-xa*xa);
-      double a=(ya*x2a-xya*xa)*denom;
-      double b=(na*xya-xa*ya)*denom;
-      double va=a+b*i;
-
-      if(fixed>0){
-        double denomf=1./(nb*x2b-xb*xb);
-        double af=(yb*x2b-xyb*xb)*denomf;
-        double bf=(nb*xyb-xb*yb)*denomf;
-        double vb=af+bf*i;
-        if(va>vb)va=vb;
-      }
-
-      noise[i]=va-140.f;
-    }
-  }
-}
-
 static void bark_noise_hybridmp(int n,const long *b,
-                               const float *f,
-                               float *noise,
-                               const int fixed){
+				const float *f,
+				float *noise,
+				const float offset,
+				const int fixed){
   long i,hi=0,lo=0,hif=0,lof=0;
   double xa=0,xb=0;
   double ya=0,yb=0;
@@ -699,7 +615,7 @@
       /* find new lo/hi */
       int bi=b[i]>>16;
       for(;hi<bi;hi++){
-        double bin=f[hi];
+        double bin=(f[hi]<-offset?0.:f[hi]+offset);
         if(bin>0.f){
           double nn= bin*bin;
           nn*=nn;
@@ -716,7 +632,7 @@
       }
       bi=b[i]&0xffff;
       for(;lo<bi;lo++){
-        double bin=f[lo];
+        double bin=(f[lo]<-offset?0.:f[lo]+offset);
         if(bin>0.f){
           double nn= bin*bin;
           nn*=nn;
@@ -744,7 +660,7 @@
       if(bi>n)bi=n;
 
       for(;hif<bi;hif++){
-        double bin=f[hif];
+        double bin=(f[hif]<-offset?0.:f[hif]+offset);
         if(bin>0.f){
           double nn= bin*bin;
           nn*=nn;
@@ -762,7 +678,7 @@
       bi=i-(fixed+1)/2;
       if(bi<0)bi=0;
       for(;lof<bi;lof++){
-        double bin=f[lof];
+        double bin=(f[lof]<-offset?0.:f[lof]+offset);
         if(bin>0.f){
           double nn= bin*bin;
           nn*=nn;
@@ -817,7 +733,7 @@
 
       }
 
-      noise[i]=va;
+      noise[i]=va-offset;
     }
   }
 }
@@ -859,13 +775,13 @@
   if(p->vi->noisemaskp){
     float *work=alloca(n*sizeof(float));
 
-    bark_noise_pointmp(n,p->bark,logmdct,logmask,
-		       -1);
+    bark_noise_hybridmp(n,p->bark,logmdct,logmask,
+			140.,-1);
 
     for(i=0;i<n;i++)work[i]=logmdct[i]-logmask[i];
 
     _analysis_output("medianmdct",seq,work,n,1,0);
-    bark_noise_hybridmp(n,p->bark,work,logmask,
+    bark_noise_hybridmp(n,p->bark,work,logmask,0.,
 			p->vi->noisewindowfixed);
 
     for(i=0;i<n;i++)work[i]=logmdct[i]-work[i];
