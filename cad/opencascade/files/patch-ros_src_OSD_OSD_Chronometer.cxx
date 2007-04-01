--- ros/src/OSD/OSD_Chronometer.cxx.orig	Fri Aug 26 18:19:13 2005
+++ ros/src/OSD/OSD_Chronometer.cxx	Thu Aug 10 21:57:15 2006
@@ -104,7 +104,7 @@
     // (man times,limits.h, man sysconf)
     //   cout << "Nombre de clicks par seconde : " << CLK_TCK << endl;
 //modified by NIZNHY-PKV Fri Mar 25 17:15:12 2005f
-#if defined(LIN) || defined(linux)
+#if defined(LIN) || defined(linux) || defined(__FreeBSD__)
     static long aCLK_TCK=sysconf(_SC_CLK_TCK);
     //
     Cumul_user += (Standard_Real) diffr_user / aCLK_TCK ;
