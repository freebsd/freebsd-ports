--- src/pulsecore/svolume_mmx.c.orig	2011-06-23 17:18:54.484125000 -0300
+++ src/pulsecore/svolume_mmx.c	2012-01-04 23:36:03.000000000 -0200
@@ -154,7 +154,7 @@
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
 #if defined (__i386__)
         : "m" ((pa_reg_x86)channels)
 #else
@@ -235,7 +235,7 @@
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
 #if defined (__i386__)
         : "m" ((pa_reg_x86)channels)
 #else
