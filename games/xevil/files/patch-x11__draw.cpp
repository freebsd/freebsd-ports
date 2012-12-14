--- x11/draw.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/draw.cpp	2012-05-27 06:52:59.000000000 +0900
@@ -34,6 +34,7 @@
 // in Xvars instead.
 #include "viewport.h"  
 
+using namespace std;
 
 
 // Draw functions for World
@@ -327,7 +328,7 @@
       Boolean val = 
         xvars.load_pixmap(&xdata.blockPixmaps[dpyNum][n],
                           mask,dpyNum,
-                          (char**)blocksBits[n]);
+                          (const char**)blocksBits[n]);
       if (!val) {
         cerr << "Failed to load block " << n << endl;
       }
@@ -352,7 +353,7 @@
       Boolean val = 
         xvars.load_pixmap(&xdata.posterPixmaps[dpyNum][n],
                           &xdata.posterMasks[dpyNum][n],
-                          dpyNum,(char**)posters[n].id);
+                          dpyNum,(const char**)posters[n].id);
       if (!val) {
         cerr << "Failed to load poster " << n << endl;
       }
@@ -363,7 +364,7 @@
     for (n = 0; n < W_ALL_DOORS_NUM; n++) {
       Boolean val = 
         xvars.load_pixmap(&xdata.doorPixmaps[dpyNum][n],NULL,dpyNum,
-                          (char**)doorPixmapBits[n]);
+                          (const char**)doorPixmapBits[n]);
       if (!val) {
         cerr << "Failed to load door block " << n << endl;
       }
@@ -376,7 +377,7 @@
         xvars.load_pixmap(&xdata.moverSquarePixmaps[dpyNum][n],
                           &xdata.moverSquareMasks[dpyNum][n],
                           dpyNum,
-                          (char**)moverSquarePixmapBits[n]);
+                          (const char**)moverSquarePixmapBits[n]);
       if (!val) {
         cerr << "Failed to mover square " << n << endl;
       }
@@ -400,7 +401,7 @@
         xvars.load_pixmap(&xdata.moverPixmaps[dpyNum][n],
                           &xdata.moverMasks[dpyNum][n],
                           dpyNum,
-                          (char**)moverPixmapBits[n]);
+                          (const char**)moverPixmapBits[n]);
       if (!val) {
         cerr << "Failed to load mover " << n << endl;
       }
@@ -411,7 +412,7 @@
     for (n = 0; n < W_ALL_BACKGROUNDS_NUM; n++) {
       Boolean val = 
         xvars.load_pixmap(&xdata.backgroundPixmaps[dpyNum][n],NULL,dpyNum,
-                          (char**)backgrounds[n].id);
+                          (const char**)backgrounds[n].id);
       if (!val) {
         cerr << "Failed to load background " << n << endl;
       }
@@ -422,7 +423,7 @@
     for (n = 0; n < W_ALL_OUTSIDES_NUM; n++) {
       Boolean val = 
         xvars.load_pixmap(&xdata.outsidePixmaps[dpyNum][n],NULL,dpyNum,
-                          (char**)outsides[n].id);
+                          (const char**)outsides[n].id);
       if (!val) {
         cerr << "Failed to load outside " << n << endl;
       }
@@ -689,7 +690,7 @@
           assert(tickPixmapBits[tt][hp] != PH_AUTO_GEN);
           xvars.load_pixmap(&xdata.tickPixmaps[dpyNum][tt][hp],
                             &xdata.tickMasks[dpyNum][tt][hp],
-                            dpyNum,(char**)tickPixmapBits[tt][hp]);
+                            dpyNum,(const char**)tickPixmapBits[tt][hp]);
         }
       }
     }
@@ -1020,7 +1021,7 @@
   for (dpyNum = 0; dpyNum < xvars.dpyMax; dpyNum++) {
     Boolean val = xvars.load_pixmap(&xdata.pixmap[dpyNum],
                                     &xdata.mask[dpyNum],
-                                    dpyNum,(char**)fireBits);
+                                    dpyNum,(const char**)fireBits);
     if (!val) {
       cerr << "Failed to load fire graphics." << endl;
     }
@@ -1292,7 +1293,7 @@
         Boolean val = 
           xvars.load_pixmap(&movingXdata.pixmaps[dpyNum][n][m],
                             &movingXdata.masks[dpyNum][n][m],
-                            dpyNum,(char**)mc.pixmapBits[n][m]);
+                            dpyNum,(const char**)mc.pixmapBits[n][m]);
         if (!val) {
           cerr << "load_pixmap() failed for "
                << mc.physicalContext.className 
