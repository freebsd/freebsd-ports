--- src/modules/module-detect.c.orig	2016-05-10 12:28:04 UTC
+++ src/modules/module-detect.c
@@ -160,8 +160,7 @@ static int detect_oss(pa_core *c, int ju
                 continue;
 
         } else if (sscanf(line, "pcm%u: ", &device) == 1) {
-            /* FreeBSD support, the devices are named /dev/dsp0.0, dsp0.1 and so on */
-            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u.0", device);
+            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u", device);
 
             if (!pa_module_load(c, "module-oss", args))
                 continue;
