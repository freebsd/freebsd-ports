--- src/Sigma.cpp.orig	Tue Nov 26 20:47:24 2002
+++ src/Sigma.cpp	Sun Sep 12 00:30:15 2004
@@ -75,9 +75,9 @@
 
 if (uv.type!=MN_REAL && Opr!=2) Error_flag=true,AppControl->AddError("Upper value must be integer");
 
-if (Opr==0 && uv.R>10000) Error_flag=true,AppControl->AddError(QObject::tr("Sigma: Count is too high"));
-if (Opr==1 && uv.R>10000) Error_flag=true,AppControl->AddError(QObject::tr("Pii: Count is too high"));
-if (Opr==3 && uv.R>10000) Error_flag=true,AppControl->AddError(QObject::tr("Loop: Count is too high"));
+if (Opr==0 && uv.mpl.m.R>10000) Error_flag=true,AppControl->AddError(QObject::tr("Sigma: Count is too high"));
+if (Opr==1 && uv.mpl.m.R>10000) Error_flag=true,AppControl->AddError(QObject::tr("Pii: Count is too high"));
+if (Opr==3 && uv.mpl.m.R>10000) Error_flag=true,AppControl->AddError(QObject::tr("Loop: Count is too high"));
 
 }
 
@@ -90,7 +90,7 @@
 
 math_node zero,sum,val;
 
-zero.R=0;
+zero.mpl.m.R=0;
 zero.type=MN_REAL;
 
 integer=NULL;
@@ -109,8 +109,8 @@
 
    if (integer) AppControl->integer_server->Protect(int_no);
    
-   lv=Lower->Calculate().R;
-   uv=Upper->Calculate().R;
+   lv=Lower->Calculate().mpl.m.R;
+   uv=Upper->Calculate().mpl.m.R;
    
    n=floor(uv);
 
@@ -121,7 +121,7 @@
    if (Opr==0) { // SIGMA
    sum=Inner->Calculate();
    for(i=0;i<(n-1);i++) {
-       if (integer) (*integer).R+=1;
+       if (integer) (*integer).mpl.m.R+=1;
        sum=mpl_add(sum,Inner->Calculate());
    }
    }
@@ -136,7 +136,7 @@
    if (Opr==1) {  // PII
    sum=Inner->Calculate();
    for(i=0;i<(n-1);i++) {
-       if (integer) (*integer).R+=1;
+       if (integer) (*integer).mpl.m.R+=1;
        sum=mpl_mul(sum,Inner->Calculate());
 
    }
@@ -148,23 +148,23 @@
    int count=100;
    double h=(uv-lv) / ( 2 * (double)count );
    
-   (*integer).R=lv; 
+   (*integer).mpl.m.R=lv; 
    sum=Inner->Calculate();
    
    for(i=0;i<count;i++) {
      
-       (*integer).R=lv+2*k*h-h;    
+       (*integer).mpl.m.R=lv+2*k*h-h;    
        val.SetReal(4.0);
        sum=mpl_add(sum,mpl_mul(Inner->Calculate(),val));
 
-       (*integer).R=lv+2*k*h;
+       (*integer).mpl.m.R=lv+2*k*h;
        val.SetReal(2.0);
        sum=mpl_add(sum,mpl_mul(Inner->Calculate(),val));
 
        k=k+1.0;
    }
 
-   (*integer).R=uv;
+   (*integer).mpl.m.R=uv;
    sum=mpl_sub(sum,Inner->Calculate());
    val.SetReal(h/3.0);
    sum=mpl_mul(sum,val);
