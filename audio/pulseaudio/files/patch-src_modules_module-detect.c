--- src/modules/module-detect.c.orig	2015-09-10 04:51:41 UTC
+++ src/modules/module-detect.c
@@ -46,7 +46,9 @@ PA_MODULE_DESCRIPTION("Detect available 
 PA_MODULE_VERSION(PACKAGE_VERSION);
 PA_MODULE_LOAD_ONCE(true);
 PA_MODULE_USAGE("just-one=<boolean>");
+#ifdef __linux__
 PA_MODULE_DEPRECATED("Please use module-udev-detect instead of module-detect!");
+#endif
 
 static const char* const valid_modargs[] = {
     "just-one",
@@ -157,8 +159,7 @@ static int detect_oss(pa_core *c, int ju
                 continue;
 
         } else if (sscanf(line, "pcm%u: ", &device) == 1) {
-            /* FreeBSD support, the devices are named /dev/dsp0.0, dsp0.1 and so on */
-            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u.0", device);
+            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u", device);
 
             if (!pa_module_load(c, "module-oss", args))
                 continue;
