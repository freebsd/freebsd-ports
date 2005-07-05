--- krita/plugins/cimg/CImg.h.orig	Tue Jun 28 02:31:30 2005
+++ krita/plugins/cimg/CImg.h	Tue Jun 28 02:32:10 2005
@@ -5135,7 +5135,7 @@
       if (ny1<0 || ny0>=dimy()) return *this;
       if (ny0<0) { nx0-=ny0*(nx1-nx0)/(ny1-ny0); ny0=0; }
       if (ny1>=dimy()) { nx1+=(ny1-dimy())*(nx0-nx1)/(ny1-ny0); ny1=dimy()-1;}
-      const unsigned int dmax = (unsigned int)cimg::max(std::abs(nx1-nx0),ny1-ny0), whz = width*height*depth;
+      const unsigned int dmax = (unsigned int)cimg::max(std::abs((long int)(nx1-nx0)),(long int)(ny1-ny0)), whz = width*height*depth;
       const float px = dmax?(nx1-nx0)/(float)dmax:0, py = dmax?(ny1-ny0)/(float)dmax:0;
       float x = (float)nx0, y = (float)ny0;
       if (opacity>=1) for (unsigned int t=0; t<=dmax; t++) {
