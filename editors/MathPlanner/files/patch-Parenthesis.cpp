--- src/Parenthesis.cpp.orig	Fri Oct 11 20:25:46 2002
+++ src/Parenthesis.cpp	Sun Sep 12 00:28:02 2004
@@ -23,7 +23,7 @@
   value=Inner->Calculate();
 
   if (Opr==3) {
-         if (value.type==MN_REAL) value.SetReal(fabs(value.R));			
+         if (value.type==MN_REAL) value.SetReal(fabs(value.mpl.m.R));			
          else if (value.type==MN_COMPLEX) value.SetReal(mpl_cmodul(value.Complex()));
          else if (value.type==MN_VECTOR) value.SetReal(mpl_length(value.Vector()));
          else Error_flag=true,AppControl->AddError(QObject::tr("Value type is not supported"));
