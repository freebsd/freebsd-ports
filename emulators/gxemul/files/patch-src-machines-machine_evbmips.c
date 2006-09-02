--- src/machines/machine_evbmips.c.orig	Mon Jul 17 17:33:05 2006
+++ src/machines/machine_evbmips.c	Mon Jul 17 17:35:04 2006
@@ -176,6 +176,11 @@
 	snprintf(tmps, sizeof(tmps), "0x%08x", machine->physical_ram_in_mb<<20);
 	add_environment_string_dual(cpu, &env, &tmpptr, "memsize", tmps);
 
+#if 1	/* XXX: FreeBSD wants this to figure out the clock speed. */
+	snprintf(tmps, sizeof(tmps), "%d", machine->emulated_hz/1000);
+	add_environment_string_dual(cpu, &env, &tmpptr, "khz", tmps);
+#endif
+
 	add_environment_string_dual(cpu, &env, &tmpptr, "yamonrev", "02.06");
 
 	/*  End of env:  */
