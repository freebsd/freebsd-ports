--- alsactl/wait.c.orig	2026-02-18 15:43:08 UTC
+++ alsactl/wait.c
@@ -112,7 +112,7 @@
 		return err;
 	}
 
-	clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
+	clock_gettime(CLOCK_MONOTONIC, &start_time);
 
 	dbg("Waiting for card %d to become ready (timeout=%lld seconds)", cardno, timeout);
 
@@ -120,7 +120,7 @@
 		long long diff, remaining = 0;
 		long long sync_time_val = -1;
 
-		clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+		clock_gettime(CLOCK_MONOTONIC, &now);
 
 		/* Read current Boot control values */
 		err = read_boot_params(handle, &boot_time_val, &sync_time_val, &restore_time_val, NULL);
