--- src/ucm/main.c.orig	2026-02-18 14:13:29.140351000 +0000
+++ src/ucm/main.c	2026-02-18 14:13:52.105863000 +0000
@@ -1166,7 +1166,7 @@
 		return err;
 	}
 
-	clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
+	clock_gettime(CLOCK_MONOTONIC, &start_time);
 
 	/* increase timeout to allow restore controls using udev/systemd */
 	/* when timeout limit exceeds */
@@ -1175,7 +1175,7 @@
 	while (1) {
 		long long diff, remaining = 0;
 
-		clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+		clock_gettime(CLOCK_MONOTONIC, &now);
 
 		err = boot_info(uc_mgr, &boot_time_val, &boot_synctime_val, &restore_time_val, &primary_card);
 		if (err < 0)
