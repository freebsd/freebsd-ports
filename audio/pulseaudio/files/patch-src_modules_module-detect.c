--- src/modules/module-detect.c.orig	2010-11-26 01:45:43.000000000 +0100
+++ src/modules/module-detect.c	2011-03-03 00:35:10.000000000 +0100
@@ -50,7 +50,9 @@ PA_MODULE_DESCRIPTION("Detect available 
 PA_MODULE_VERSION(PACKAGE_VERSION);
 PA_MODULE_LOAD_ONCE(TRUE);
 PA_MODULE_USAGE("just-one=<boolean>");
+#ifdef __linux__
 PA_MODULE_DEPRECATED("Please use module-udev-detect instead of module-detect!");
+#endif
 
 static const char* const valid_modargs[] = {
     "just-one",
@@ -161,8 +163,7 @@ static int detect_oss(pa_core *c, int ju
                 continue;
 
         } else if (sscanf(line, "pcm%u: ", &device) == 1) {
-            /* FreeBSD support, the devices are named /dev/dsp0.0, dsp0.1 and so on */
-            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u.0", device);
+            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u", device);
 
             if (!pa_module_load(c, "module-oss", args))
                 continue;
