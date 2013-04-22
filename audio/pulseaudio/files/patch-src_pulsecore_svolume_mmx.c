--- src/pulsecore/svolume_mmx.c.orig	2011-06-23 20:18:54.484125000 +0000
+++ src/pulsecore/svolume_mmx.c	2013-04-18 09:22:42.000000000 +0000
@@ -154,9 +154,9 @@
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
 #if defined (__i386__)
-        : "m" ((pa_reg_x86)channels)
+        : "m" (channels)
 #else
         : "r" ((pa_reg_x86)channels)
 #endif
@@ -235,9 +235,9 @@
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
 #if defined (__i386__)
-        : "m" ((pa_reg_x86)channels)
+        : "m" (channels)
 #else
         : "r" ((pa_reg_x86)channels)
 #endif
