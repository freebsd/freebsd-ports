--- src/modules/module-detect.c.orig	2009-11-22 22:57:05.000000000 -0500
+++ src/modules/module-detect.c	2010-06-17 19:20:39.000000000 -0400
@@ -161,8 +161,7 @@
                 continue;
 
         } else if (sscanf(line, "pcm%u: ", &device) == 1) {
-            /* FreeBSD support, the devices are named /dev/dsp0.0, dsp0.1 and so on */
-            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u.0", device);
+            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u", device);
 
             if (!pa_module_load(c, "module-oss", args))
                 continue;
