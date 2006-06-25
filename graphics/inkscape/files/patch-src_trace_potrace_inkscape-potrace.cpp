--- src/trace/potrace/inkscape-potrace.cpp.orig	Sat Jun 24 22:46:26 2006
+++ src/trace/potrace/inkscape-potrace.cpp	Sun Jun 25 01:29:20 2006
@@ -54,6 +54,121 @@ static void potraceStatusCallback(double
     //      (Inkscape::Trace::Potrace::PotraceTracingEngine *)userData;
 }
 
+#ifndef log2
+static const double
+ln2 = 0.6931471805599452862268,
+two54   =  1.80143985094819840000e+16,  /* 43500000 00000000 */
+Lg1 = 6.666666666666735130e-01,  /* 3FE55555 55555593 */
+Lg2 = 3.999999999940941908e-01,  /* 3FD99999 9997FA04 */
+Lg3 = 2.857142874366239149e-01,  /* 3FD24924 94229359 */
+Lg4 = 2.222219843214978396e-01,  /* 3FCC71C5 1D8E78AF */
+Lg5 = 1.818357216161805012e-01,  /* 3FC74664 96CB03DE */
+Lg6 = 1.531383769920937332e-01,  /* 3FC39A09 D078C69F */
+Lg7 = 1.479819860511658591e-01;  /* 3FC2F112 DF3E5244 */
+
+static const double zero = 0.0;
+
+#if BYTE_ORDER == BIG_ENDIAN
+
+typedef union
+{
+      double value;
+        struct
+	      {
+		      u_int32_t msw;
+		          u_int32_t lsw;
+			    } parts;
+} ieee_double_shape_type;
+
+#endif
+
+#if BYTE_ORDER == LITTLE_ENDIAN
+
+typedef union
+{
+      double value;
+        struct
+	      {
+		      u_int32_t lsw;
+		          u_int32_t msw;
+			    } parts;
+} ieee_double_shape_type;
+
+#endif
+
+#define EXTRACT_WORDS(ix0,ix1,d)                                \
+    do {                                                            \
+	  ieee_double_shape_type ew_u;                                  \
+	  ew_u.value = (d);                                             \
+	  (ix0) = ew_u.parts.msw;                                       \
+	  (ix1) = ew_u.parts.lsw;                                       \
+    } while (0)
+
+#define GET_HIGH_WORD(i,d)                                      \
+    do {                                                            \
+	  ieee_double_shape_type gh_u;                                  \
+	  gh_u.value = (d);                                             \
+	  (i) = gh_u.parts.msw;                                         \
+    } while (0)
+
+#define SET_HIGH_WORD(d,v)                                      \
+    do {                                                            \
+	  ieee_double_shape_type sh_u;                                  \
+	  sh_u.value = (d);                                             \
+	  sh_u.parts.msw = (v);                                         \
+	  (d) = sh_u.value;                                             \
+    } while (0)
+
+static double
+_log2(double x)
+{
+    double hfsq,f,s,z,R,w,t1,t2,dk;
+    int32_t k,hx,i,j;
+    u_int32_t lx;
+
+    EXTRACT_WORDS(hx,lx,x);
+
+    k=0;
+    if (hx < 0x00100000) {			/* x < 2**-1022  */
+	if (((hx&0x7fffffff)|lx)==0) 
+	    return -two54/zero;		/* log(+-0)=-inf */
+	if (hx<0) return (x-x)/zero;	/* log(-#) = NaN */
+	k -= 54; x *= two54; /* subnormal number, scale up x */
+	GET_HIGH_WORD(hx,x);
+    }
+    if (hx >= 0x7ff00000) return x+x;
+    k += (hx>>20)-1023;
+    hx &= 0x000fffff;
+    i = (hx+0x95f64)&0x100000;
+    SET_HIGH_WORD(x,hx|(i^0x3ff00000));	/* normalize x or x/2 */
+    k += (i>>20);
+    f = x-1.0;
+    dk = (double)k;
+    if((0x000fffff&(2+hx))<3) {	/* |f| < 2**-20 */
+	if (f==zero)
+	    return (dk);
+	R = f*f*(0.5-0.33333333333333333*f);
+	return (dk-(R-f)/ln2);
+    }
+    s = f/(2.0+f);
+    z = s*s;
+    i = hx-0x6147a;
+    w = z*z;
+    j = 0x6b851-hx;
+    t1= w*(Lg2+w*(Lg4+w*Lg6));
+    t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
+    i |= j;
+    R = t2+t1;
+    if(i>0) {
+	hfsq=0.5*f*f;
+	return (dk-(hfsq-s*(hfsq+R)-f)/ln2);
+    } else
+	return (dk-((s*(f-R))-f)/ln2);
+}
+
+#define log2(x) _log2(x)
+#endif
+
 
 
 
