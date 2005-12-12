--- resample.c.orig	Mon Nov  3 16:06:32 2003
+++ resample.c	Sun Dec 11 03:27:20 2005
@@ -6,7 +6,6 @@
 
 #include "a52.h"
 #include "mm_accel.h"
-#include "config.h"
 #include "../libpostproc/mangle.h"
 
 int (* a52_resample) (float * _f, int16_t * s16)=NULL;
@@ -14,6 +13,7 @@
 #include "resample_c.c"
 
 #ifdef ARCH_X86
+#include "../../libavutil/common.h"
 #include "resample_mmx.c"
 #endif
 
@@ -24,7 +24,6 @@
     if(mm_accel&MM_ACCEL_X86_MMX){
 	tmp=a52_resample_MMX(flags,chans);
 	if(tmp){
-	    if(a52_resample==NULL) av_log(NULL, AV_LOG_INFO, "Using MMX optimized resampler\n");
 	    a52_resample=tmp;
 	    return tmp;
 	}
@@ -33,11 +32,9 @@
 
     tmp=a52_resample_C(flags,chans);
     if(tmp){
-	if(a52_resample==NULL) av_log(NULL, AV_LOG_INFO, "No accelerated resampler found\n");
 	a52_resample=tmp;
 	return tmp;
     }
     
-    av_log(NULL, AV_LOG_ERROR, "Unimplemented resampler for mode 0x%X -> %d channels conversion - Contact MPlayer developers!\n", flags, chans);
     return NULL;
 }
