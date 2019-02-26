--- src/CubicSDRDefs.h.orig	2018-06-08 03:58:55 UTC
+++ src/CubicSDRDefs.h
@@ -2,6 +2,7 @@
 // SPDX-License-Identifier: GPL-2.0+
 
 #pragma once
+#include <sys/param.h>
 
 #define CUBICSDR_TITLE "" CUBICSDR_BUILD_TITLE
 
@@ -16,7 +17,11 @@
         #ifdef __APPLE__
             #include <machine/endian.h>
         #else
-            #include <endian.h>
+	    #ifdef __FreeBSD__
+		#include <sys/endian.h>
+	    #else
+		 #include <endian.h>
+	    #endif
         #endif
     #endif
 #endif
@@ -62,4 +67,4 @@ const char filePathSeparator =
 
 //The maximum number of listed sample rates for a device, to be able to handle 
 //devices returning an insane amount because they have quasi-continuous ranges (UHD...)
-#define DEVICE_SAMPLE_RATES_MAX_NB     25
\ No newline at end of file
+#define DEVICE_SAMPLE_RATES_MAX_NB     25
