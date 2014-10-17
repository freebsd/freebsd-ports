--- ./src/gallium/drivers/r300/r300_chipset.c.orig	2014-01-06 22:15:40.000000000 +0100
+++ ./src/gallium/drivers/r300/r300_chipset.c	2014-02-23 22:01:50.000000000 +0100
@@ -53,6 +53,21 @@
     if (!os_get_process_name(proc_name, sizeof(proc_name)))
         return;
 
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
         if (strcmp(list[i], proc_name) == 0) {
             caps->zmask_ram = 0;
