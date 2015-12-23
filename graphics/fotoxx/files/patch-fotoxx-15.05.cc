--- fotoxx-15.05.cc.orig	2015-05-01 09:40:38 UTC
+++ fotoxx-15.05.cc
@@ -139,6 +139,8 @@
 
 #define EX                                                                 //  disable extern declarations
 #include "fotoxx.h"                                                        //  (variables in fotoxx.h are defined)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 /**************************************************************************/
 
@@ -335,7 +337,9 @@ int initzfunc(void *)
    char     procfile[20], buff[200];
    char     KBshortsU[200], KBshortsI[200];
    char     tonefile[200], badnews[200];
+#ifdef __linux__
    double   freememory, cachememory;
+#endif
    float    exifver = 0;
    FILE     *fid;
    STATB    statb;
@@ -445,6 +449,7 @@ int initzfunc(void *)
 
    //  check free memory and suggest image size limits
 
+#ifdef __linux__
    parseprocfile("/proc/meminfo","MemFree:",&freememory,0);                //  get amount of free memory
    parseprocfile("/proc/meminfo","Cached:",&cachememory,0);
    freememory = (freememory + cachememory) / 1024;                         //  megabytes
@@ -452,6 +457,7 @@ int initzfunc(void *)
    printz("image size limits for good performance: \n");
    printz("  view: %.0f megapixels \n",(freememory-100)/6);                //  F + preview, 3 bytes/pixel each
    printz("  edit: %.0f megapixels \n",(freememory-100)/54);               //  + E0/E1/E3/ER, 12 bytes/pixel each
+#endif
 
    //  update KB shortcuts if needed
 
@@ -531,7 +537,13 @@ int initzfunc(void *)
    screenhh = gdk_screen_get_height(screen);
    printz("screen width: %d  height: %d \n",screenww,screenhh);
 
+#ifdef __linux__
    NWT = get_nprocs();                                                     //  get SMP CPU count
+#endif
+#ifdef __FreeBSD__
+   size_t	len = sizeof(NWT);
+   sysctlbyname("hw.ncpu",&NWT,&len,NULL,0);
+#endif
    if (NWT <= 0) NWT = 2;
    if (NWT > max_threads) NWT = max_threads;                               //  compile time limit
    printz("using %d threads \n",NWT);
