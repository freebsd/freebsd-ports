diff --git a/src/gallium/drivers/r300/r300_chipset.c b/src/gallium/drivers/r300/r300_chipset.c
index 11061ed..daf990e 100644
--- src/gallium/drivers/r300/r300_chipset.c
+++ src/gallium/drivers/r300/r300_chipset.c
@@ -48,6 +48,21 @@ static void r300_apply_hyperz_blacklist(struct r300_capabilities* caps)
     };
     int i;
 
+#if defined(__DragonFly__) || \
+    defined(__FreeBSD__) ||   \
+    defined(__NetBSD__) ||    \
+    defined(__OpenBSD__)
+    const char *progname, *program_invocation_short_name;
+
+    progname = getprogname();
+    program_invocation_short_name = strrchr(progname, '/');
+    if (program_invocation_short_name) {
+        program_invocation_short_name++;
+    } else {
+        program_invocation_short_name = progname;
+    }
+#endif
+
     for (i = 0; i < Elements(list); i++) {
         if (strcmp(list[i], program_invocation_short_name) == 0) {
             caps->zmask_ram = 0;
