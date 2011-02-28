--- src/pulsecore/svolume_mmx.c.orig	2010-02-20 13:53:25.000000000 +0100
+++ src/pulsecore/svolume_mmx.c	2010-02-20 13:54:22.000000000 +0100
@@ -153,7 +153,7 @@ pa_volume_s16ne_mmx (int16_t *samples, i
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
         : "rm" ((pa_reg_x86)channels)
         : "cc"
     );
@@ -229,7 +229,7 @@ pa_volume_s16re_mmx (int16_t *samples, i
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
         : "rm" ((pa_reg_x86)channels)
         : "cc"
     );
