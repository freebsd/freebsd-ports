--- src/Maxmin.cpp.orig	Fri Oct 11 19:16:00 2002
+++ src/Maxmin.cpp	Sun Sep 12 00:26:29 2004
@@ -26,10 +26,10 @@
   b=Outer->Calculate();
 
   if (a.type==MN_REAL && b.type==MN_REAL) {
-    if (Opr==0) if (a.R<b.R) value=a;
+    if (Opr==0) if (a.mpl.m.R<b.mpl.m.R) value=a;
                 else value=b;
 
-    if (Opr==1) if (a.R>b.R) value=a;
+    if (Opr==1) if (a.mpl.m.R>b.mpl.m.R) value=a;
                 else value=b;
   }
   else { Error_flag=true; AppControl->AddError(QObject::tr("Only Real numbers are supported")); }
