--- src/Real_math.cpp.orig	Sat Feb  8 21:02:34 2003
+++ src/Real_math.cpp	Sat Feb  8 21:02:54 2003
@@ -26,8 +26,8 @@
 bool mpl_modul(mpl_real a,mpl_real b)
 {
 mpl_real c=(a/b);
-mpl_real ca=round(c*MODUL_ACCURACY);
-mpl_real cb=round(c)*MODUL_ACCURACY;
+mpl_real ca=floor(c*MODUL_ACCURACY);
+mpl_real cb=floor(c)*MODUL_ACCURACY;
 
 if (ca==cb) return(true);
 return(false);
