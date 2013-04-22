--- src/pulsecore/svolume_sse.c.orig	2013-04-19 14:02:51.000000000 +0000
+++ src/pulsecore/svolume_sse.c	2013-04-19 14:03:14.000000000 +0000
@@ -155,7 +155,7 @@
 
         : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
 #if defined (__i386__)
-        : "m" ((pa_reg_x86)channels)
+        : "m" (channels)
 #else
         : "r" ((pa_reg_x86)channels)
 #endif
@@ -249,7 +249,7 @@
 
         : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
 #if defined (__i386__)
-        : "m" ((pa_reg_x86)channels)
+        : "m" (channels)
 #else
         : "r" ((pa_reg_x86)channels)
 #endif
