$FreeBSD$

--- ../src/share/native/java/lang/fdlibm/src/e_pow.c	11 Jul 2001 21:40:20 -0000	1.1.1.1
+++ ../src/share/native/java/lang/fdlibm/src/e_pow.c	30 Apr 2003 04:42:09 -0000
@@ -57,6 +57,9 @@
  */
 
 #include "fdlibm.h"
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+#include "math_private.h"
+#endif
 
 #ifdef __STDC__
 static const double
@@ -108,8 +111,13 @@
 	int hx,hy,ix,iy;
 	unsigned lx,ly;
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	EXTRACT_WORDS(hx,lx,x);
+	EXTRACT_WORDS(hy,ly,y);
+#else
 	hx = __HI(x); lx = __LO(x);
 	hy = __HI(y); ly = __LO(y);
+#endif
 	ix = hx&0x7fffffff;  iy = hy&0x7fffffff;
 
     /* y==zero: x**0 = 1 */
@@ -195,14 +203,22 @@
 	    u = ivln2_h*t;	/* ivln2_h has 21 sig. bits */
 	    v = t*ivln2_l-w*ivln2;
 	    t1 = u+v;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_LOW_WORD(t1,0);
+#else
 	    __LO(t1) = 0;
+#endif
 	    t2 = v-(t1-u);
 	} else {
 	    double s2,s_h,s_l,t_h,t_l;
 	    n = 0;
 	/* take care subnormal number */
 	    if(ix<0x00100000)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+		{ax *= two53; n -= 53; GET_HIGH_WORD(ix,ax); }
+#else
 		{ax *= two53; n -= 53; ix = __HI(ax); }
+#endif
 	    n  += ((ix)>>20)-0x3ff;
 	    j  = ix&0x000fffff;
 	/* determine interval */
@@ -210,17 +226,29 @@
 	    if(j<=0x3988E) k=0;		/* |x|<sqrt(3/2) */
 	    else if(j<0xBB67A) k=1;	/* |x|<sqrt(3)   */
 	    else {k=0;n+=1;ix -= 0x00100000;}
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_HIGH_WORD(ax,ix);
+#else
 	    __HI(ax) = ix;
+#endif
 
 	/* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
 	    u = ax-bp[k];		/* bp[0]=1.0, bp[1]=1.5 */
 	    v = one/(ax+bp[k]);
 	    s = u*v;
 	    s_h = s;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_LOW_WORD(s_h,0);
+#else
 	    __LO(s_h) = 0;
+#endif
 	/* t_h=ax+bp[k] High */
 	    t_h = zero;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_HIGH_WORD(t_h,((ix>>1)|0x20000000)+0x00080000+(k<<18));
+#else
 	    __HI(t_h)=((ix>>1)|0x20000000)+0x00080000+(k<<18); 
+#endif
 	    t_l = ax - (t_h-bp[k]);
 	    s_l = v*((u-s_h*t_h)-s_h*t_l);
 	/* compute log(ax) */
@@ -229,21 +257,33 @@
 	    r += s_l*(s_h+s);
 	    s2  = s_h*s_h;
 	    t_h = 3.0+s2+r;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_LOW_WORD(t_h,0);
+#else
 	    __LO(t_h) = 0;
+#endif
 	    t_l = r-((t_h-3.0)-s2);
 	/* u+v = s*(1+...) */
 	    u = s_h*t_h;
 	    v = s_l*t_h+t_l*s;
 	/* 2/(3log2)*(s+...) */
 	    p_h = u+v;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_LOW_WORD(p_h,0);
+#else
 	    __LO(p_h) = 0;
+#endif
 	    p_l = v-(p_h-u);
 	    z_h = cp_h*p_h;		/* cp_h+cp_l = 2/(3*log2) */
 	    z_l = cp_l*p_h+p_l*cp+dp_l[k];
 	/* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
 	    t = (double)n;
 	    t1 = (((z_h+z_l)+dp_h[k])+t);
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_LOW_WORD(t1,0);
+#else
 	    __LO(t1) = 0;
+#endif
 	    t2 = z_l-(((t1-t)-dp_h[k])-z_h);
 	}
 
@@ -252,12 +292,20 @@
 
     /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
 	y1  = y;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	SET_LOW_WORD(y1,0);
+#else
 	__LO(y1) = 0;
+#endif
 	p_l = (y-y1)*t1+y*t2;
 	p_h = y1*t1;
 	z = p_l+p_h;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	EXTRACT_WORDS(j,i,z);
+#else
 	j = __HI(z);
 	i = __LO(z);
+#endif
 	if (j>=0x40900000) {				/* z >= 1024 */
 	    if(((j-0x40900000)|i)!=0)			/* if z > 1024 */
 		return s*huge*huge;			/* overflow */
@@ -281,13 +329,21 @@
 	    n = j+(0x00100000>>(k+1));
 	    k = ((n&0x7fffffff)>>20)-0x3ff;	/* new k for n */
 	    t = zero;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	    SET_HIGH_WORD(t,n&~(0x000fffff>>k));
+#else
 	    __HI(t) = (n&~(0x000fffff>>k));
+#endif
 	    n = ((n&0x000fffff)|0x00100000)>>(20-k);
 	    if(j<0) n = -n;
 	    p_h -= t;
 	}
 	t = p_l+p_h;
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	SET_LOW_WORD(t,0);
+#else
 	__LO(t) = 0;
+#endif
 	u = t*lg2_h;
 	v = (p_l-(t-p_h))*lg2+t*lg2_l;
 	z = u+v;
@@ -296,9 +352,17 @@
 	t1  = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
 	r  = (z*t1)/(t1-two)-(w+z*w);
 	z  = one-(r-z);
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	GET_HIGH_WORD(j,z);
+#else
 	j  = __HI(z);
+#endif
 	j += (n<<20);
 	if((j>>20)<=0) z = scalbn(z,n);	/* subnormal output */
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+	else SET_HIGH_WORD(z,j);
+#else
 	else __HI(z) += (n<<20);
+#endif
 	return s*z;
 }
