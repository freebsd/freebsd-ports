--- ./fotoxx-14.02.2.cc.orig	2014-02-05 20:42:34.000000000 +0100
+++ ./fotoxx-14.02.2.cc	2014-02-06 10:32:37.000000000 +0100
@@ -133,7 +133,8 @@
 
 #define EX                                                                 //  disable extern declarations
 #include "fotoxx.h"
-
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 //  fotoxx main program
 
@@ -451,7 +452,6 @@
    char           procfile[20], buff[200];
    char           KBshortsU[200], KBshortsI[200];
    char           favorites_config[200], badnews[200];
-   double         freememory, cachememory;                                 //  available memory at startup
    float          exifver = 0;
    FILE           *fid;
    struct stat    statb;
@@ -542,19 +542,12 @@
    
    snprintf(URS_filename,200,"%s/undo_nn",tempdir);                        //  /run/shm/fotoxx-nnnnnn/undo_nn
 
-   //  check free memory and suggest image size limits
-
-   parseprocfile("/proc/meminfo","MemFree:",&freememory,null);             //  get amount of free memory
-   parseprocfile("/proc/meminfo","Cached:",&cachememory,null);
-   freememory = (freememory + cachememory) / 1024;                         //  megabytes
-   printz("free memory: %.0f MB \n",freememory);
-   printz("image size limits for good performance: \n");                   //  v.13.04
-   printz("  view: %.0f megapixels \n",(freememory-100)/6);                //  F + preview, 3 bytes/pixel each
-   printz("  edit: %.0f megapixels \n",(freememory-100)/54);               //  + E0/E1/E3/ER, 12 bytes/pixel each
-
    //  miscellaneous
 
-   Nwt = get_nprocs();                                                     //  get SMP CPU count
+   //Nwt = get_nprocs();                                                     //  get SMP CPU count
+   size_t         len = sizeof(Nwt);
+   sysctlbyname("hw.ncpu",&Nwt,&len,NULL,0);
+
    if (Nwt <= 0) Nwt = 2;
    if (Nwt > max_threads) Nwt = max_threads;                               //  compile time limit
    printz("using %d threads \n",Nwt);
@@ -4321,31 +4314,6 @@
 }
 
 
-/**************************************************************************/
-
-//  popup a warning message if real memory is below specified threshold
-//  returns margin: real memory - threshold, in megabytes 
-//  (+ if enough memory, - if not)
-//  the popup message only appears if real memory < threshold
-//  the popup message goes away after a few seconds
-
-int warn_memory(int req_mb)
-{
-   double   freemem, cachemem;
-   int      act_mb, gap_mb;
-   cchar    *message = ZTX("warning: real memory %d MB < required %d MB \n"
-                           "response time may become very long \n");
-
-   parseprocfile("/proc/meminfo","MemFree:",&freemem,null);                //  get current free memory
-   parseprocfile("/proc/meminfo","Cached:",&cachemem,null);
-   act_mb = (freemem + cachemem) / 1024;                                   //  megabytes
-   gap_mb = act_mb - req_mb;
-   if (gap_mb > -10) return gap_mb;
-   zpopup_message(message,act_mb,req_mb);                                  //  deficit > 10 MB
-   return gap_mb;                                      
-}
-
-
 /**************************************************************************
       PXM pixmap functions - RGB float pixel map
       pixel RGB values may range from 0.0 to 255.99
@@ -4386,9 +4354,6 @@
       return 0;
    }
 
-   int req_mb = ww * hh * 12 / mega;                                       //  warn if memory low
-   warn_memory(req_mb);
-
    PXM *pxm = (PXM *) zmalloc(sizeof(PXM),"PXM");                          //  0.45 sec for 116 megapix image (1.4 GB)
    pxm->ww = ww;
    pxm->hh = hh;
@@ -4806,9 +4771,6 @@
 
 PXB * PXB_make(int ww, int hh)
 {
-   int req_mb = ww * hh * 3 / mega;                                        //  warn if memory low 
-   warn_memory(req_mb);
-
    PXB *pxb = (PXB *) zmalloc(sizeof(PXB),"PXB");
    strcpy(pxb->wmi,"pxbpix");
    pxb->pixbuf = gdk_pixbuf_new(GDKRGB,0,8,ww,hh);
@@ -4857,9 +4819,6 @@
 
 PXB * PXB_copy(PXB *pxb1)
 {
-   int req_mb = pxb1->ww * pxb1->hh * 3 / mega;                            //  warn if memory low
-   warn_memory(req_mb);
-
    PXB *pxb2 = (PXB *) zmalloc(sizeof(PXB),"PXB");
    strcpy(pxb2->wmi,"pxbpix");
    pxb2->pixbuf = gdk_pixbuf_copy(pxb1->pixbuf);
@@ -4876,9 +4835,6 @@
 PXB * PXB_rescale(PXB *pxb1, int ww2, int hh2)
 {
    GdkPixbuf   *pixbuf2 = 0;
-   int req_mb = ww2 * hh2 * 3 / mega;                                      //  warn if memory low
-   warn_memory(req_mb);
-   
    if (strEqu(interpolation,"tiles"))                                      //  v.13.05
       pixbuf2 = gdk_pixbuf_scale_simple(pxb1->pixbuf,ww2,hh2,GDK_INTERP_TILES);
    else if (strEqu(interpolation,"hyperbolic"))
