--- ext/bigdecimal/bigdecimal.c.orig	2009-06-13 01:11:45.000000000 +0400
+++ ext/bigdecimal/bigdecimal.c	2009-06-13 01:11:49.000000000 +0400
@@ -306,17 +306,19 @@
 BigDecimal_dump(int argc, VALUE *argv, VALUE self)
 {
     ENTER(5);
-    char sz[50];
     Real *vp;
     char *psz;
     VALUE dummy;
+    volatile VALUE dump;
+
     rb_scan_args(argc, argv, "01", &dummy);
     GUARD_OBJ(vp,GetVpValue(self,1));
-    sprintf(sz,"%lu:",VpMaxPrec(vp)*VpBaseFig());
-    psz = ALLOCA_N(char,(unsigned int)VpNumOfChars(vp,"E")+strlen(sz));
-    sprintf(psz,"%s",sz);
+    dump = rb_str_new(0,VpNumOfChars(vp,"E")+50);
+    psz = RSTRING_PTR(dump);
+    sprintf(psz,"%lu:",VpMaxPrec(vp)*VpBaseFig());
     VpToString(vp, psz+strlen(psz), 0, 0);
-    return rb_str_new2(psz);
+    rb_str_resize(dump, strlen(psz));
+    return dump;
 }
 
 /*
@@ -520,6 +522,7 @@
     ENTER(5);
     int e,n,i,nf;
     U_LONG v,b,j;
+    volatile VALUE str;
     char *psz,*pch;
     Real *p;
 
@@ -527,14 +530,14 @@
 
     /* Infinity or NaN not converted. */
     if(VpIsNaN(p)) {
-       VpException(VP_EXCEPTION_NaN,"Computation results to 'NaN'(Not a Number)",0);
-       return Qnil;
+       VpException(VP_EXCEPTION_NaN,"Computation results to 'NaN'(Not a Number)",1);
+       return Qnil;		/* not reached */
     } else if(VpIsPosInf(p)) {
-       VpException(VP_EXCEPTION_INFINITY,"Computation results to 'Infinity'",0);
-       return Qnil;
+       VpException(VP_EXCEPTION_INFINITY,"Computation results to 'Infinity'",1);
+       return Qnil;		/* not reached */
     } else if(VpIsNegInf(p)) {
-       VpException(VP_EXCEPTION_INFINITY,"Computation results to '-Infinity'",0);
-       return Qnil;
+       VpException(VP_EXCEPTION_INFINITY,"Computation results to '-Infinity'",1);
+       return Qnil;		/* not reached */
     }
 
     e = VpExponent10(p);
@@ -544,7 +547,8 @@
         e = VpGetSign(p)*p->frac[0];
         return INT2FIX(e);
     }
-    psz = ALLOCA_N(char,(unsigned int)(e+nf+2));
+    str = rb_str_new(0, e+nf+2);
+    psz = RSTRING_PTR(str);
 
     n = (e+nf-1)/nf;
     pch = psz;
@@ -589,17 +593,21 @@
     double d;
     S_LONG e;
     char *buf;
+    volatile VALUE str;
 
     GUARD_OBJ(p,GetVpValue(self,1));
     if(VpVtoD(&d, &e, p)!=1) return rb_float_new(d);
-    buf = ALLOCA_N(char,(unsigned int)VpNumOfChars(p,"E"));
+    if (e > DBL_MAX_10_EXP) goto erange;
+    str = rb_str_new(0, VpNumOfChars(p,"E"));
+    buf = RSTRING_PTR(str);
     VpToString(p, buf, 0, 0);
     errno = 0;
     d = strtod(buf, 0);
     if(errno == ERANGE) {
+      erange:
        VpException(VP_EXCEPTION_OVERFLOW,"BigDecimal to Float conversion",0);
-       if(d>0.0) return rb_float_new(DBL_MAX);
-       else      return rb_float_new(-DBL_MAX);
+       if(d>0.0) d = VpGetDoublePosInf();
+       else      d = VpGetDoubleNegInf();
     }
     return rb_float_new(d);
 }
@@ -1491,6 +1499,7 @@
     int   fmt=0;   /* 0:E format */
     int   fPlus=0; /* =0:default,=1: set ' ' before digits ,set '+' before digits. */
     Real  *vp;
+    volatile VALUE str;
     char  *psz;
     char   ch;
     U_LONG nc;
@@ -1527,14 +1536,16 @@
     }
     if(mc>0) nc += (nc + mc - 1) / mc + 1;
 
-    psz = ALLOCA_N(char,(unsigned int)nc);
+    str = rb_str_new(0, nc);
+    psz = RSTRING_PTR(str);
 
     if(fmt) {
         VpToFString(vp, psz, mc, fPlus);
     } else {
         VpToString (vp, psz, mc, fPlus);
     }
-    return rb_str_new2(psz);
+    rb_str_resize(str, strlen(psz));
+    return str;
 }
 
 /* Splits a BigDecimal number into four parts, returned as an array of values.
@@ -1566,24 +1577,29 @@
 {
     ENTER(5);
     Real *vp;
-    VALUE obj,obj1;
+    VALUE obj,str;
     S_LONG e;
     S_LONG s;
     char *psz1;
 
     GUARD_OBJ(vp,GetVpValue(self,1));
-    psz1 = ALLOCA_N(char,(unsigned int)VpNumOfChars(vp,"E"));
+    str = rb_str_new(0, VpNumOfChars(vp,"E"));
+    psz1 = RSTRING_PTR(str);
     VpSzMantissa(vp,psz1);
     s = 1;
     if(psz1[0]=='-') {
-        s = -1; ++psz1;
+	int len = strlen(psz1+1);
+
+	memmove(psz1, psz1+1, len);
+	psz1[len] = '\0';
+        s = -1;
     }
     if(psz1[0]=='N') s=0; /* NaN */
     e = VpExponent10(vp);
-    obj1 = rb_str_new2(psz1);
     obj  = rb_ary_new2(4);
     rb_ary_push(obj, INT2FIX(s));
-    rb_ary_push(obj, obj1);
+    rb_ary_push(obj, str);
+    rb_str_resize(str, strlen(psz1));
     rb_ary_push(obj, INT2FIX(10));
     rb_ary_push(obj, INT2NUM(e));
     return obj;
@@ -1616,20 +1632,22 @@
 {
     ENTER(5);
     Real *vp;
-    VALUE obj;
+    volatile VALUE obj;
     unsigned int nc;
-    char *psz1;
-    char *pszAll;
+    char *psz, *tmp;
 
     GUARD_OBJ(vp,GetVpValue(self,1));
     nc = VpNumOfChars(vp,"E");
     nc +=(nc + 9) / 10;
 
-    psz1   = ALLOCA_N(char,nc);
-    pszAll = ALLOCA_N(char,nc+256);
-    VpToString(vp, psz1, 10, 0);
-    sprintf(pszAll,"#<BigDecimal:%lx,'%s',%lu(%lu)>",self,psz1,VpPrec(vp)*VpBaseFig(),VpMaxPrec(vp)*VpBaseFig());
-    obj = rb_str_new2(pszAll);
+    obj = rb_str_new(0, nc+256);
+    psz = RSTRING_PTR(obj);
+    sprintf(psz,"#<BigDecimal:%lx,'",self);
+    tmp = psz + strlen(psz);
+    VpToString(vp, tmp, 10, 0);
+    tmp += strlen(tmp);
+    sprintf(tmp,"',%lu(%lu)>",VpPrec(vp)*VpBaseFig(),VpMaxPrec(vp)*VpBaseFig());
+    rb_str_resize(obj, strlen(psz));
     return obj;
 }
 
@@ -2482,6 +2500,7 @@
     int  sign=1;
     Real *vp = NULL;
     U_LONG mf = VpGetPrecLimit();
+    volatile VALUE buf;
 
     mx = (mx + BASE_FIG - 1) / BASE_FIG + 1;    /* Determine allocation unit. */
     if(szVal) {
@@ -2509,7 +2528,8 @@
 
     /* Skip all '_' after digit: 2006-6-30 */
     ni = 0;
-    psz = ALLOCA_N(char,strlen(szVal)+1);
+    buf = rb_str_new(0,strlen(szVal)+1);
+    psz = RSTRING_PTR(buf);
     i   = 0;
     ipn = 0;
     while((psz[i]=szVal[ipn])!=0) {
@@ -3601,7 +3621,7 @@
                 nc += fprintf(fp, "0.");
                 n = a->Prec;
                 for(i=0;i < n;++i) {
-                 m = BASE1;
+		    m = BASE1;
                     e = a->frac[i];
                     while(m) {
                         nn = e / m;
