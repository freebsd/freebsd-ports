--- src/modules/module-detect.c.orig	2016-05-10 12:28:04 UTC
+++ src/modules/module-detect.c
@@ -160,11 +160,45 @@ static int detect_oss(pa_core *c, int ju
                 continue;
 
         } else if (sscanf(line, "pcm%u: ", &device) == 1) {
-            /* FreeBSD support, the devices are named /dev/dsp0.0, dsp0.1 and so on */
-            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u.0", device);
+            pa_snprintf(args, sizeof(args), "device=/dev/dsp%u", device);
+            pa_module *m = pa_module_load(c, "module-oss", args);
 
-            if (!pa_module_load(c, "module-oss", args))
+            if (!m)
+                continue;
+
+            if (!pa_endswith(line, "default"))
+                continue;
+
+            const char *p = strrchr(line, '(');
+
+            if (!p)
                 continue;
+
+            if (!c->default_sink && (strstr(p, "play") || (strstr(p, "p:") && !strstr(p, "(0p:")))) {
+                uint32_t idx = PA_IDXSET_INVALID;
+                pa_sink *s;
+                PA_IDXSET_FOREACH(s, c->sinks, idx) {
+                    if (s->module == m) {
+                        if (!pa_namereg_set_default_sink(c, s))
+                            pa_log_error("failed to set default sink for device: /dev/dsp%u", device);
+
+                        break;
+                    }
+                }
+            }
+
+            if (!c->default_source && (strstr(p, "rec") || (strstr(p, "r:") && !strstr(p, "/0r:")))) {
+                uint32_t idx = PA_IDXSET_INVALID;
+                pa_source *s;
+                PA_IDXSET_FOREACH(s, c->sources, idx) {
+                    if (s->module == m) {
+                        if (!pa_namereg_set_default_source(c, s))
+                            pa_log_error("failed to set default source for device: /dev/dsp%u", device);
+
+                        break;
+                    }
+                }
+            }
         }
 
         n++;
