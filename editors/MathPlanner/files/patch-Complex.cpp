--- src/Complex.cpp.orig	Fri Oct 11 20:26:22 2002
+++ src/Complex.cpp	Sun Sep 12 00:18:04 2004
@@ -26,8 +26,8 @@
 
   if (value.type!=MN_REAL) Error_flag=true,AppControl->AddError(QObject::tr("Value type is not supported by this function"));
 
-  if (Mode==1) value.SetComplex(mpl_cang(value.R));
-  if (Mode==0) value.SetComplex(mpl_cang(mpl_rad(value.R)));
+  if (Mode==1) value.SetComplex(mpl_cang(value.mpl.m.R));
+  if (Mode==0) value.SetComplex(mpl_cang(mpl_rad(value.mpl.m.R)));
   return(value);
 }
 
