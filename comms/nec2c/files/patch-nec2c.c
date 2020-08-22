--- nec2c.c.orig	2004-02-23 09:30:55 UTC
+++ nec2c.c
@@ -794,7 +794,7 @@ int main( int argc, char **argv )
 	      continue; /* continue card input loop */
 
 	    ntyp[idx]=3;
-	    x11r[idx]=- tmp1;
+	    x11r[idx]= - tmp1;
 
 	    continue; /* continue card input loop */
 	  }
@@ -1218,7 +1218,7 @@ int main( int argc, char **argv )
 	      if( iperf != 1)
 	      {
 		if( sig < 0.)
-		  sig=- sig/(59.96*wlam);
+		  sig= - sig/(59.96*wlam);
 
 		epsc= cmplx( epsr, -sig*wlam*59.96);
 		zrati=1./ csqrt( epsc);
@@ -3197,7 +3197,7 @@ void conect( int ignd )
 	  ix= jco[i];
 	  if( ix <= 0)
 	  {
-	    ix=- ix;
+	    ix= - ix;
 	    ixx = ix-1;
 	    x[ixx]= xa;
 	    y[ixx]= ya;
@@ -3931,7 +3931,7 @@ void efld( double xi, double yi, double zi, double ai,
   {
     if( ip == 1)
       ijx=1;
-    rfl=- rfl;
+    rfl= - rfl;
     salpr= salpj* rfl;
     zij= zi- rfl* zj;
     zp= xij* cabj+ yij* sabj+ zij* salpr;
@@ -4032,7 +4032,7 @@ void efld( double xi, double yi, double zi, double ai,
 	}
 	else
 	{
-	  px=- yij/ xymag;
+	  px= - yij/ xymag;
 	  py= xij/ xymag;
 	  cth= zij/ rmag;
 	  zrsin= csqrt(1.0 - zratx*zratx*(1.0 - cth*cth) );
@@ -4107,7 +4107,7 @@ void efld( double xi, double yi, double zi, double ai,
 
   /* displace observation point for thin wire approximation */
   zij= zi+ zj;
-  salpr=- salpj;
+  salpr= - salpj;
   rhox= sabj* zij- salpr* yij;
   rhoy= salpr* xij- cabj* zij;
   rhoz= cabj* yij- sabj* xij;
@@ -4123,7 +4123,7 @@ void efld( double xi, double yi, double zi, double ai,
   {
     rh= ai/ sqrt( rh);
     if( rhoz < 0.)
-      rh=- rh;
+      rh= - rh;
     xo= xi+ rh* rhox;
     yo= yi+ rh* rhoy;
     zo= zi+ rh* rhoz;
@@ -4215,18 +4215,18 @@ void eksc( double s, double z, double rh, double xk, i
   gzp1= gp1* z1a;
   gzp2= gp2* z2a;
   *ezs=  CONST1*(( gz2- gz1)* cs* xk-( gzp2+ gzp1)* ss);
-  *ezc=- CONST1*(( gz2+ gz1)* ss* xk+( gzp2- gzp1)* cs);
+  *ezc= - CONST1*(( gz2+ gz1)* ss* xk+( gzp2- gzp1)* cs);
   *erk= CONST1*( gp2- gp1)* rh;
   intx(- shk, shk, rhk, ij, &cint, &sint);
-  *ezk=- CONST1*( gzp2- gzp1+ xk* xk* cmplx( cint,- sint));
+  *ezk= - CONST1*( gzp2- gzp1+ xk* xk* cmplx( cint,- sint));
   gzp1= gzp1* z1a;
   gzp2= gzp2* z2a;
 
   if( rh >= 1.0e-10)
   {
-    *ers=- CONST1*(( gzp2+ gzp1+ gz2+ gz1)*
+    *ers= - CONST1*(( gzp2+ gzp1+ gz2+ gz1)*
 	ss-( z2a* gz2- z1a* gz1)* cs*xk)/ rh;
-    *erc=- CONST1*(( gzp2- gzp1+ gz2- gz1)*
+    *erc= - CONST1*(( gzp2- gzp1+ gz2- gz1)*
 	cs+( z2a* gz2+ z1a* gz1)* ss*xk)/ rh;
     return;
   }
@@ -4304,16 +4304,16 @@ void ekscx( double bx, double s, double z,
   }
 
   *ezs= CONST1*(( gz2- gz1)* cs* xk-( gzp2+ gzp1)* ss);
-  *ezc=- CONST1*(( gz2+ gz1)* ss* xk+( gzp2- gzp1)* cs);
-  *ers=- CONST1*(( z2a* grp2+ z1a* grp1+ gr2+ gr1)*ss
+  *ezc= - CONST1*(( gz2+ gz1)* ss* xk+( gzp2- gzp1)* cs);
+  *ers= - CONST1*(( z2a* grp2+ z1a* grp1+ gr2+ gr1)*ss
       -( z2a* gr2- z1a* gr1)* cs* xk);
-  *erc=- CONST1*(( z2a* grp2- z1a* grp1+ gr2- gr1)*cs
+  *erc= - CONST1*(( z2a* grp2- z1a* grp1+ gr2- gr1)*cs
       +( z2a* gr2+ z1a* gr1)* ss* xk);
   *erk= CONST1*( grk2- grk1);
   intx(- shk, shk, rhk, ij, &cint, &sint);
   bk= b* xk;
   bk2= bk* bk*.25;
-  *ezk=- CONST1*( gzp2- gzp1+ xk* xk*(1.- bk2)*
+  *ezk= - CONST1*( gzp2- gzp1+ xk* xk*(1.- bk2)*
       cmplx( cint,- sint)-bk2*( gzz2- gzz1));
 
   return;
@@ -4373,10 +4373,10 @@ void etmns( double p1, double p2, double p3, double p4
     set= sin( p3);
     pxl= cth* cph* cet- sph* set;
     pyl= cth* sph* cet+ cph* set;
-    pzl=- sth* cet;
-    wx=- sth* cph;
-    wy=- sth* sph;
-    wz=- cth;
+    pzl= - sth* cet;
+    wx= - sth* cph;
+    wy= - sth* sph;
+    wz= - cth;
     qx= wy* pzl- wz* pyl;
     qy= wz* pxl- wx* pzl;
     qz= wx* pyl- wy* pxl;
@@ -4405,7 +4405,7 @@ void etmns( double p1, double p2, double p3, double p4
       {
 	for( i = 0; i < n; i++ )
 	{
-	  arg=- TP*( wx* x[i]+ wy* y[i]+ wz* z[i]);
+	  arg= - TP*( wx* x[i]+ wy* y[i]+ wz* z[i]);
 	  e[i]=-( pxl* cab[i]+ pyl* sab[i]+ pzl*
 	      salp[i])* cmplx( cos( arg), sin( arg));
 	}
@@ -4415,11 +4415,11 @@ void etmns( double p1, double p2, double p3, double p4
 	  tt1=( pyl* cph- pxl* sph)*( rrh- rrv);
 	  cx= rrv* pxl- tt1* sph;
 	  cy= rrv* pyl+ tt1* cph;
-	  cz=- rrv* pzl;
+	  cz= - rrv* pzl;
 
 	  for( i = 0; i < n; i++ )
 	  {
-	    arg=- TP*( wx* x[i]+ wy* y[i]- wz* z[i]);
+	    arg= - TP*( wx* x[i]+ wy* y[i]- wz* z[i]);
 	    e[i]= e[i]-( cx* cab[i]+ cy* sab[i]+
 		cz* salp[i])* cmplx(cos( arg), sin( arg));
 	  }
@@ -4438,7 +4438,7 @@ void etmns( double p1, double p2, double p3, double p4
 	i++;
 	i1 += 2;
 	i2 = i1+1;
-	arg=- TP*( wx* px[i]+ wy* py[i]+ wz* pz[i]);
+	arg= - TP*( wx* px[i]+ wy* py[i]+ wz* pz[i]);
 	tt1= cmplx( cos( arg), sin( arg))* psalp[i]* RETA;
 	e[i2]=( qx* t1x[i]+ qy* t1y[i]+ qz* t1z[i])* tt1;
 	e[i1]=( qx* t2x[i]+ qy* t2y[i]+ qz* t2z[i])* tt1;
@@ -4459,7 +4459,7 @@ void etmns( double p1, double p2, double p3, double p4
 	i++;
 	i1 += 2;
 	i2 = i1+1;
-	arg=- TP*( wx* px[i]+ wy* py[i]- wz* pz[i]);
+	arg= - TP*( wx* px[i]+ wy* py[i]- wz* pz[i]);
 	tt1= cmplx( cos( arg), sin( arg))* psalp[i]* RETA;
 	e[i2]= e[i2]+( cx* t1x[i]+ cy* t1y[i]+ cz* t1z[i])* tt1;
 	e[i1]= e[i1]+( cx* t2x[i]+ cy* t2y[i]+ cz* t2z[i])* tt1;
@@ -4471,7 +4471,7 @@ void etmns( double p1, double p2, double p3, double p4
     /* incident plane wave, elliptic polarization. */
     tt1=-(CPLX_01)* p6;
     if( ipr == 3)
-      tt1=- tt1;
+      tt1= - tt1;
 
     if( n != 0)
     {
@@ -4481,7 +4481,7 @@ void etmns( double p1, double p2, double p3, double p4
 
       for( i = 0; i < n; i++ )
       {
-	arg=- TP*( wx* x[i]+ wy* y[i]+ wz* z[i]);
+	arg= - TP*( wx* x[i]+ wy* y[i]+ wz* z[i]);
 	e[i]=-( cx* cab[i]+ cy* sab[i]+ cz*
 	    salp[i])* cmplx( cos( arg), sin( arg));
       }
@@ -4491,11 +4491,11 @@ void etmns( double p1, double p2, double p3, double p4
 	tt2=( cy* cph- cx* sph)*( rrh- rrv);
 	cx= rrv* cx- tt2* sph;
 	cy= rrv* cy+ tt2* cph;
-	cz=- rrv* cz;
+	cz= - rrv* cz;
 
 	for( i = 0; i < n; i++ )
 	{
-	  arg=- TP*( wx* x[i]+ wy* y[i]- wz* z[i]);
+	  arg= - TP*( wx* x[i]+ wy* y[i]- wz* z[i]);
 	  e[i]= e[i]-( cx* cab[i]+ cy* sab[i]+
 	      cz* salp[i])* cmplx(cos( arg), sin( arg));
 	}
@@ -4518,7 +4518,7 @@ void etmns( double p1, double p2, double p3, double p4
       i++;
       i1 += 2;
       i2 = i1+1;
-      arg=- TP*( wx* px[i]+ wy* py[i]+ wz* pz[i]);
+      arg= - TP*( wx* px[i]+ wy* py[i]+ wz* pz[i]);
       tt2= cmplx( cos( arg), sin( arg))* psalp[i]* RETA;
       e[i2]=( cx* t1x[i]+ cy* t1y[i]+ cz* t1z[i])* tt2;
       e[i1]=( cx* t2x[i]+ cy* t2y[i]+ cz* t2z[i])* tt2;
@@ -4539,7 +4539,7 @@ void etmns( double p1, double p2, double p3, double p4
       i++;
       i1 += 2;
       i2 = i1+1;
-      arg=- TP*( wx* px[i]+ wy* py[i]- wz* pz[i]);
+      arg= - TP*( wx* px[i]+ wy* py[i]- wz* pz[i]);
       tt1= cmplx( cos( arg), sin( arg))* psalp[i]* RETA;
       e[i2]= e[i2]+( cx* t1x[i]+ cy* t1y[i]+ cz* t1z[i])* tt1;
       e[i1]= e[i1]+( cx* t2x[i]+ cy* t2y[i]+ cz* t2z[i])* tt1;
@@ -4604,7 +4604,7 @@ void etmns( double p1, double p2, double p3, double p4
 
     } /* if( arg >= 1.e-30) */
 
-    arg=- TP* r;
+    arg= - TP* r;
     tt1= cmplx( cos( arg), sin( arg));
 
     if( i < n )
@@ -4775,7 +4775,7 @@ complex double  fbar( complex double p )
 
     for( i = 1; i <= 100; i++ )
     {
-      pow=- pow* zs/ (double)i;
+      pow= - pow* zs/ (double)i;
       term= pow/(2.* i+1.);
       sum= sum+ term;
       tms= creal( term* conj( term));
@@ -4793,7 +4793,7 @@ complex double  fbar( complex double p )
   if( creal( z) < 0.)
   {
     minus=1;
-    z=- z;
+    z= - z;
   }
   else
     minus=0;
@@ -4804,13 +4804,13 @@ complex double  fbar( complex double p )
 
   for( i = 1; i <= 6; i++ )
   {
-    term =- term*(2.*i -1.)* zs;
+    term = - term*(2.*i -1.)* zs;
     sum += term;
   }
 
   if( minus == 1)
     sum -= 2.* SP* z* cexp( z* z);
-  fbar=- sum;
+  fbar= - sum;
 
   return( fbar );
 }
@@ -4882,7 +4882,7 @@ void fblock( int nrow, int ncol, int imax, int ipsym )
       {
 	deter= ssx[i+j*nop];
 	ssx[i+(j+kk)*nop]= deter;
-	ssx[i+kk+(j+kk)*nop]=- deter;
+	ssx[i+kk+(j+kk)*nop]= - deter;
 	ssx[i+kk+j*nop]= deter;
       }
     }
@@ -4908,14 +4908,14 @@ void ffld( double thet, double phi,
   complex double zrsin, rrv, rrh, rrv1, rrh1, rrv2, rrh2;
   complex double tix, tiy, tiz, zscrn, ex, ey, ez, gx, gy, gz;
 
-  phx=- sin( phi);
+  phx= - sin( phi);
   phy= cos( phi);
   roz= cos( thet);
   rozs= roz;
   thx= roz* phy;
-  thy=- roz* phx;
-  thz=- sin( thet);
-  rox=- thz* phy;
+  thy= - roz* phx;
+  thz= - sin( thet);
+  rox= - thz* phy;
   roy= thz* phx;
 
   jump = FALSE;
@@ -4954,11 +4954,11 @@ void ffld( double thet, double phi,
 	    zrsin= csqrt(1.- zrati2* zrati2* thz* thz);
 	    rrv2=-( roz- zrati2* zrsin)/( roz+ zrati2* zrsin);
 	    rrh2=( zrati2* roz- zrsin)/( zrati2* roz+ zrsin);
-	    darg=- TP*2.* ch* roz;
+	    darg= - TP*2.* ch* roz;
 	  }
 	} /* if( ifar > 1) */
 
-	roz=- roz;
+	roz= - roz;
 	ccx= cix;
 	ccy= ciy;
 	ccz= ciz;
@@ -5147,7 +5147,7 @@ void ffld( double thet, double phi,
   rfl=-1.;
   for( ip = 0; ip < ksymp; ip++ )
   {
-    rfl=- rfl;
+    rfl= - rfl;
     rrz= roz* rfl;
     fflds( rox, roy, rrz, &cur[n], &gx, &gy, &gz);
 
@@ -5161,9 +5161,9 @@ void ffld( double thet, double phi,
 
     if( iperf == 1)
     {
-      gx=- gx;
-      gy=- gy;
-      gz=- gz;
+      gx= - gx;
+      gy= - gy;
+      gz= - gz;
     }
     else
     {
@@ -5285,7 +5285,7 @@ void gfld( double rho, double phi, double rz,
       thet= PI*.5;
 
     ffld( thet, phi, eth, epi);
-    arg=- TP* r;
+    arg= - TP* r;
     exa= cmplx( cos( arg), sin( arg))/ r;
     *eth= *eth* exa;
     *epi= *epi* exa;
@@ -5296,10 +5296,10 @@ void gfld( double rho, double phi, double rz,
   /* computation of space and ground waves. */
   u= ux;
   u2= u* u;
-  phx=- sin( phi);
+  phx= - sin( phi);
   phy= cos( phi);
   rx= rho* phy;
-  ry=- rho* phx;
+  ry= - rho* phx;
   cix=CPLX_00;
   ciy=CPLX_00;
   ciz=CPLX_00;
@@ -5348,7 +5348,7 @@ void gfld( double rho, double phi, double rz,
     /* constant, sine, and cosine current distributions */
     for( k = 0; k < 2; k++ )
     {
-      rfl=- rfl;
+      rfl= - rfl;
       riz= rz- z[i]* rfl;
       rxyz= sqrt( rix* rix+ riy* riy+ riz* riz);
       rnx= rix/ rxyz;
@@ -5409,7 +5409,7 @@ void gfld( double rho, double phi, double rz,
 
   } /* for( i = 0; i < n; i++ ) */
 
-  arg=- TP* r;
+  arg= - TP* r;
   exa= cmplx( cos( arg), sin( arg));
   cix= cix* exa;
   ciy= ciy* exa;
@@ -5418,8 +5418,8 @@ void gfld( double rho, double phi, double rz,
   rny= ry/ r;
   rnz= rz/ r;
   thx= rnz* phy;
-  thy=- rnz* phx;
-  thz=- rho/ r;
+  thy= - rnz* phx;
+  thz= - rho/ r;
   *eth= cix* thx+ ciy* thy+ ciz* thz;
   *epi= cix* phx+ ciy* phy;
   *erd= cix* rnx+ ciy* rny+ ciz* rnz;
@@ -5477,8 +5477,8 @@ void gwave( complex double *erv, complex double *ezv,
     cpp2=1.0e-20;
 
   cpp= sqrt( cpp2);
-  rk1=- TPJ* r1;
-  rk2=- TPJ* r2;
+  rk1= - TPJ* r1;
+  rk2= - TPJ* r2;
   t1=1. -u2* cpp2;
   t2= csqrt( t1);
   t3=(1. -1./ rk1)/ rk1;
@@ -5542,7 +5542,7 @@ void gx( double zz, double rh, double xk,
   r= sqrt( r2);
   rkz= xk* r;
   *gz= cmplx( cos( rkz),- sin( rkz))/ r;
-  *gzp=- cmplx(1.0, rkz)* *gz/ r2;
+  *gzp= - cmplx(1.0, rkz)* *gz/ r2;
 
   return;
 }
@@ -5580,7 +5580,7 @@ void gxx( double zz, double rh, double a, double a2, d
   if( ira != 1)
   {
     *g3=( *g3+ *gzp)* rh;
-    *gzp=- zz* c1* gz;
+    *gzp= - zz* c1* gz;
 
     if( rh <= 1.0e-10)
     {
@@ -5596,11 +5596,11 @@ void gxx( double zz, double rh, double a, double a2, d
   } /* if( ira != 1) */
 
   t2=.5* a;
-  *g2=- t2* c1* gz;
+  *g2= - t2* c1* gz;
   *g2p= t2* gz* c2/ r2;
   *g3= rh2* *g2p- a* gz* c1;
   *g2p= *g2p* zz;
-  *gzp=- zz* c1* gz;
+  *gzp= - zz* c1* gz;
 
   return;
 }
@@ -5897,7 +5897,7 @@ void hintg( double xi, double yi, double zi )
 
   for( ip = 1; ip <= ksymp; ip++ )
   {
-    rfl=- rfl;
+    rfl= - rfl;
     rz= zi- zj* rfl;
     rsq= rx* rx+ ry* ry+ rz* rz;
 
@@ -5925,12 +5925,12 @@ void hintg( double xi, double yi, double zi )
     {
       if( iperf == 1)
       {
-	f1x=- f1x;
-	f1y=- f1y;
-	f1z=- f1z;
-	f2x=- f2x;
-	f2y=- f2y;
-	f2z=- f2z;
+	f1x= - f1x;
+	f1y= - f1y;
+	f1z= - f1z;
+	f2x= - f2x;
+	f2y= - f2y;
+	f2z= - f2z;
       }
       else
       {
@@ -5944,7 +5944,7 @@ void hintg( double xi, double yi, double zi )
 	}
 	else
 	{
-	  pxx=- ry/ xymag;
+	  pxx= - ry/ xymag;
 	  pyy= rx/ xymag;
 	  cth= rz/ r;
 	  rrv= csqrt(1.- zrati* zrati*(1.- cth* cth));
@@ -5997,7 +5997,7 @@ void hsfld( double xi, double yi, double zi, double ai
 
   for( ip = 0; ip < ksymp; ip++ )
   {
-    rfl=- rfl;
+    rfl= - rfl;
     salpr= salpj* rfl;
     zij= zi- rfl* zj;
     zp= xij* cabj+ yij* sabj+ zij* salpr;
@@ -6061,7 +6061,7 @@ void hsfld( double xi, double yi, double zi, double ai
 	}
 	else
 	{
-	  px=- yij/ xymag;
+	  px= - yij/ xymag;
 	  py= xij/ xymag;
 	  cth= zij/ rmag;
 	  rrv= csqrt(1.- zratx* zratx*(1.- cth* cth));
@@ -6137,7 +6137,7 @@ void hsflx( double s, double rh, double zpx,
     }
     else
     {
-      zp=- zpx;
+      zp= - zpx;
       hss=-1.;
     }
 
@@ -6165,8 +6165,8 @@ void hsflx( double s, double rh, double zpx,
       t1= z1* ekr1/ r1;
       t2= z2a* ekr2/ r2;
       *hps=( cdk*( ekr2- ekr1)- CPLX_01* sdk*( t2+ t1))* hss;
-      *hpc=- sdk*( ekr2+ ekr1)- CPLX_01* cdk*( t2- t1);
-      cons=- CPLX_01/(2.* TP* rh);
+      *hpc= - sdk*( ekr2+ ekr1)- CPLX_01* cdk*( t2- t1);
+      cons= - CPLX_01/(2.* TP* rh);
       *hps= cons* *hps;
       *hpc= cons* *hpc;
       return;
@@ -6807,7 +6807,7 @@ void move( double rox, double roy, double roz, double 
   yx= sph* cth;
   yy= sph* sth* sps+ cph* cps;
   yz= sph* sth* cps- cph* sps;
-  zx=- sth;
+  zx= - sth;
   zy= cth* sps;
   zz= cth* cps;
 
@@ -7338,15 +7338,15 @@ void netwk( complex double *cm, complex double *cmb,
 	  y12r=0.;
 	  y12i=1./( x11r[j]* sin( y22r));
 	  y11r= x12r[j];
-	  y11i=- y12i* cos( y22r);
+	  y11i= - y12i* cos( y22r);
 	  y22r= x22r[j];
 	  y22i= y11i+ x22i[j];
 	  y11i= y11i+ x12i[j];
 
 	  if( ntyp[j] != 2)
 	  {
-	    y12r=- y12r;
-	    y12i=- y12i;
+	    y12r= - y12r;
+	    y12i= - y12i;
 	  }
 
 	} /* if( ntyp[j] <= 1) */
@@ -8013,7 +8013,7 @@ void patch( int nx, int ny,
 
     if( xa >= 1.0e-6)
     {
-      t1x[mi]=- ynv/ xa;
+      t1x[mi]= - ynv/ xa;
       t1y[mi]= xnv/ xa;
       t1z[mi]=0.;
     }
@@ -8256,10 +8256,10 @@ void subph( int nx, int ny )
     psalp[mia]= saln;
 
     if( ix == 2)
-      yt=- yt;
+      yt= - yt;
 
     if( (ix == 1) || (ix == 3) )
-      xt=- xt;
+      xt= - xt;
 
     mia++;
   }
@@ -8470,7 +8470,7 @@ void qdsrc( int is, complex double v, complex double *
 
       if( ipr < 0 )
       {
-	ipr=- ipr;
+	ipr= - ipr;
 	ipr--;
 	if( -icon1[ipr-1] != jp1 )
 	  ind1=2;
@@ -8828,7 +8828,7 @@ void rdpat( void )
 	    stilta= sin( tilta);
 	    tstor1= tstor1* stilta* stilta;
 	    tstor2= tstor2* stilta* cos( tilta);
-	    emajr2=- tstor1+ tstor2+ ethm2;
+	    emajr2= - tstor1+ tstor2+ ethm2;
 	    eminr2= tstor1- tstor2+ ephm2;
 	    if( eminr2 < 0.)
 	      eminr2=0.;
@@ -9148,7 +9148,7 @@ void readgm( char *gm, int *i1, int *i2, double *x1, d
 	    (line_buf[  line_idx] >  '9')) &&
 	    (line_buf[  line_idx] != '+')  &&
 	    (line_buf[  line_idx] != '-') )
-      if( (line_buf[line_idx] == '\0') )
+      if( line_buf[line_idx] == '\0') 
       {
 	*i1= iarr[0];
 	*i2= iarr[1];
@@ -9212,7 +9212,7 @@ void readgm( char *gm, int *i1, int *i2, double *x1, d
 	    (line_buf[  line_idx] != '+')  &&
 	    (line_buf[  line_idx] != '-')  &&
 	    (line_buf[  line_idx] != '.') )
-      if( (line_buf[line_idx] == '\0') )
+      if( line_buf[line_idx] == '\0') 
       {
 	*i1= iarr[0];
 	*i2= iarr[1];
@@ -9341,7 +9341,7 @@ void readmn( char *gm, int *i1, int *i2, int *i3, int 
 	    (line_buf[  line_idx] >  '9')) &&
 	    (line_buf[  line_idx] != '+')  &&
 	    (line_buf[  line_idx] != '-') )
-      if( (line_buf[line_idx] == '\0') )
+      if( line_buf[line_idx] == '\0') 
       {
 	*i1= iarr[0];
 	*i2= iarr[1];
@@ -9407,7 +9407,7 @@ void readmn( char *gm, int *i1, int *i2, int *i3, int 
 	    (line_buf[  line_idx] != '+')  &&
 	    (line_buf[  line_idx] != '-')  &&
 	    (line_buf[  line_idx] != '.') )
-      if( (line_buf[line_idx] == '\0') )
+      if( line_buf[line_idx] == '\0') 
       {
 	*i1= iarr[0];
 	*i2= iarr[1];
@@ -9538,10 +9538,10 @@ void reflc( int ix, int iy, int iz, int itx, int nop )
 
 	  x[nx]= x[i];
 	  y[nx]= y[i];
-	  z[nx]=- e1;
+	  z[nx]= - e1;
 	  x2[nx]= x2[i];
 	  y2[nx]= y2[i];
-	  z2[nx]=- e2;
+	  z2[nx]= - e2;
 	  itagi= itag[i];
 
 	  if( itagi == 0)
@@ -9587,14 +9587,14 @@ void reflc( int ix, int iy, int iz, int itx, int nop )
 
 	  px[nx]= px[i];
 	  py[nx]= py[i];
-	  pz[nx]=- pz[i];
+	  pz[nx]= - pz[i];
 	  t1x[nx]= t1x[i];
 	  t1y[nx]= t1y[i];
-	  t1z[nx]=- t1z[i];
+	  t1z[nx]= - t1z[i];
 	  t2x[nx]= t2x[i];
 	  t2y[nx]= t2y[i];
-	  t2z[nx]=- t2z[i];
-	  psalp[nx]=- psalp[i];
+	  t2z[nx]= - t2z[i];
+	  psalp[nx]= - psalp[i];
 	  pbi[nx]= pbi[i];
 	}
 
@@ -9637,10 +9637,10 @@ void reflc( int ix, int iy, int iz, int itx, int nop )
 	  }
 
 	  x[nx]= x[i];
-	  y[nx]=- e1;
+	  y[nx]= - e1;
 	  z[nx]= z[i];
 	  x2[nx]= x2[i];
-	  y2[nx]=- e2;
+	  y2[nx]= - e2;
 	  z2[nx]= z2[i];
 	  itagi= itag[i];
 
@@ -9686,15 +9686,15 @@ void reflc( int ix, int iy, int iz, int itx, int nop )
 	  }
 
 	  px[nx]= px[i];
-	  py[nx]=- py[i];
+	  py[nx]= - py[i];
 	  pz[nx]= pz[i];
 	  t1x[nx]= t1x[i];
-	  t1y[nx]=- t1y[i];
+	  t1y[nx]= - t1y[i];
 	  t1z[nx]= t1z[i];
 	  t2x[nx]= t2x[i];
-	  t2y[nx]=- t2y[i];
+	  t2y[nx]= - t2y[i];
 	  t2z[nx]= t2z[i];
-	  psalp[nx]=- psalp[i];
+	  psalp[nx]= - psalp[i];
 	  pbi[nx]= pbi[i];
 
 	} /* for( i = m2; i <= m; i++ ) */
@@ -9738,10 +9738,10 @@ void reflc( int ix, int iy, int iz, int itx, int nop )
 	  stop(-1);
 	}
 
-	x[nx]=- e1;
+	x[nx]= - e1;
 	y[nx]= y[i];
 	z[nx]= z[i];
-	x2[nx]=- e2;
+	x2[nx]= - e2;
 	y2[nx]= y2[i];
 	z2[nx]= z2[i];
 	itagi= itag[i];
@@ -9786,16 +9786,16 @@ void reflc( int ix, int iy, int iz, int itx, int nop )
 	stop(-1);
       }
 
-      px[nx]=- px[i];
+      px[nx]= - px[i];
       py[nx]= py[i];
       pz[nx]= pz[i];
-      t1x[nx]=- t1x[i];
+      t1x[nx]= - t1x[i];
       t1y[nx]= t1y[i];
       t1z[nx]= t1z[i];
-      t2x[nx]=- t2x[i];
+      t2x[nx]= - t2x[i];
       t2y[nx]= t2y[i];
       t2z[nx]= t2z[i];
-      psalp[nx]=- psalp[i];
+      psalp[nx]= - psalp[i];
       pbi[nx]= pbi[i];
     }
 
@@ -10106,11 +10106,11 @@ void sbf( int i, int is, double *aa, double *bb, doubl
     if( jcox != 0 )
     {
       if( jcox < 0 )
-	jcox=- jcox;
+	jcox= - jcox;
       else
       {
-	sig=- sig;
-	jend=- jend;
+	sig= - sig;
+	jend= - jend;
       }
 
       jcoxx = jcox-1;
@@ -10135,7 +10135,7 @@ void sbf( int i, int is, double *aa, double *bb, doubl
       {
 	*aa= aj/ sd* sig;
 	*bb= aj/(2.* cdh);
-	*cc=- aj/(2.* sdh)* sig;
+	*cc= - aj/(2.* sdh)* sig;
 	june= iend;
       }
 
@@ -10161,14 +10161,14 @@ void sbf( int i, int is, double *aa, double *bb, doubl
       } /* if( jcox != i ) */
       else
 	if( jcox == is)
-	  *bb=- *bb;
+	  *bb= - *bb;
 
       if( iend == 1)
 	break;
 
     } /* if( jcox != 0 ) */
 
-    pm=- pp;
+    pm= - pp;
     pp=0.;
     njun1= jsno;
 
@@ -10220,9 +10220,9 @@ void sbf( int i, int is, double *aa, double *bb, doubl
 
     if( june == 1)
     {
-      *aa=- *aa* qp;
+      *aa= - *aa* qp;
       *bb=  *bb* qp;
-      *cc=- *cc* qp;
+      *cc= - *cc* qp;
       if( i != is)
 	return;
     }
@@ -10273,9 +10273,9 @@ void sbf( int i, int is, double *aa, double *bb, doubl
     }
     else
     {
-      *aa=- *aa* qp;
+      *aa= - *aa* qp;
       *bb= *bb* qp;
-      *cc=- *cc* qp;
+      *cc= - *cc* qp;
     }
 
     if( i != is)
@@ -10319,7 +10319,7 @@ void sflds( double t, complex double *e )
   {
     rhx= rhx/ rho;
     rhy= rhy/ rho;
-    phx=- rhy;
+    phx= - rhy;
     phy= rhx;
   }
 
@@ -10668,11 +10668,11 @@ void tbf( int i, int icap )
     if( jcox != 0 )
     {
       if( jcox < 0 )
-	jcox=- jcox;
+	jcox= - jcox;
       else
       {
-	sig=- sig;
-	jend=- jend;
+	sig= - sig;
+	jend= - jend;
       }
 
       jcoxx = jcox-1;
@@ -10696,7 +10696,7 @@ void tbf( int i, int icap )
       pp= pp- omc/ sd* aj;
       ax[jsnox]= aj/ sd* sig;
       bx[jsnox]= aj/(2.* cdh);
-      cx[jsnox]=- aj/(2.* sdh)* sig;
+      cx[jsnox]= - aj/(2.* sdh)* sig;
 
       if( jcox != i)
       {
@@ -10719,14 +10719,14 @@ void tbf( int i, int icap )
 
       } /* if( jcox != i) */
       else
-	bx[jsnox] =- bx[jsnox];
+	bx[jsnox] = - bx[jsnox];
 
       if( iend == 1)
 	break;
 
     } /* if( jcox != 0 ) */
 
-    pm=- pp;
+    pm= - pp;
     pp=0.;
     njun1= jsno;
 
@@ -10799,9 +10799,9 @@ void tbf( int i, int icap )
 
     for( iend = 0; iend < njun2; iend++ )
     {
-      ax[iend]=- ax[iend]* qp;
+      ax[iend]= - ax[iend]* qp;
       bx[iend]= bx[iend]* qp;
-      cx[iend]=- cx[iend]* qp;
+      cx[iend]= - cx[iend]* qp;
     }
 
     jsno= jsnop+1;
@@ -10855,9 +10855,9 @@ void tbf( int i, int icap )
   jend= njun1;
   for( iend = jend; iend < jsno; iend++ )
   {
-    ax[iend]=- ax[iend]* qp;
+    ax[iend]= - ax[iend]* qp;
     bx[iend]= bx[iend]* qp;
-    cx[iend]=- cx[iend]* qp;
+    cx[iend]= - cx[iend]* qp;
   }
 
   jsno= jsnop+1;
@@ -10947,9 +10947,9 @@ void trio( int j )
   do
   {
     if( jcox < 0 )
-      jcox=- jcox;
+      jcox= - jcox;
     else
-      jend=- jend;
+      jend= - jend;
     jcoxx = jcox-1;
 
     if( jcox != j)
@@ -11036,9 +11036,9 @@ void unere( double xob, double yob, double zob )
 
   if( ipgnd == 2)
   {
-    zr=- zr;
-    t1zr=- t1zr;
-    t2zr=- t2zr;
+    zr= - zr;
+    t1zr= - t1zr;
+    t2zr= - t2zr;
   }
 
   rx= xob- xj;
@@ -11058,7 +11058,7 @@ void unere( double xob, double yob, double zob )
   }
 
   r= sqrt( r2);
-  tt1=- TP* r;
+  tt1= - TP* r;
   tt2= tt1* tt1;
   rt= r2* r;
   er= cmplx( sin( tt1),- cos( tt1))*( CONST2* s);
@@ -11078,12 +11078,12 @@ void unere( double xob, double yob, double zob )
 
   if( iperf == 1)
   {
-    exk=- exk;
-    eyk=- eyk;
-    ezk=- ezk;
-    exs=- exs;
-    eys=- eys;
-    ezs=- ezs;
+    exk= - exk;
+    eyk= - eyk;
+    ezk= - ezk;
+    exs= - exs;
+    eys= - eys;
+    ezs= - ezs;
     return;
   }
 
@@ -11097,7 +11097,7 @@ void unere( double xob, double yob, double zob )
   }
   else
   {
-    px=- ry/ xymag;
+    px= - ry/ xymag;
     py= rx/ xymag;
     cth= rz/ sqrt( xymag* xymag+ rz* rz);
     rrv= csqrt(1.- zrati* zrati*(1.- cth* cth));
