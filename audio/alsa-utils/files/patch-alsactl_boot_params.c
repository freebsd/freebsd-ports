--- alsactl/boot_params.c.orig	2026-02-18 15:46:59 UTC
+++ alsactl/boot_params.c
@@ -629,9 +629,9 @@
 		goto out;
 	}
 
-	if (clock_gettime(CLOCK_MONOTONIC_RAW, &ts_monotonic) < 0) {
+	if (clock_gettime(CLOCK_MONOTONIC, &ts_monotonic) < 0) {
 		err = -errno;
-		error("Failed to get CLOCK_MONOTONIC_RAW: %s", strerror(errno));
+		error("Failed to get CLOCK_MONOTONIC: %s", strerror(errno));
 		goto out;
 	}
 
@@ -742,8 +742,8 @@
 			}
 
 			if (ts_monotonic.tv_sec == 0) {
-				if (clock_gettime(CLOCK_MONOTONIC_RAW, &ts_monotonic) < 0) {
-					dbg("Failed to get CLOCK_MONOTONIC_RAW: %s", strerror(errno));
+				if (clock_gettime(CLOCK_MONOTONIC, &ts_monotonic) < 0) {
+					dbg("Failed to get CLOCK_MONOTONIC: %s", strerror(errno));
 					return changes;
 				}
 			}
@@ -961,9 +961,9 @@
 	}
 	ts_realtime.tv_nsec = 0;
 
-	if (clock_gettime(CLOCK_MONOTONIC_RAW, &ts_monotonic) < 0) {
+	if (clock_gettime(CLOCK_MONOTONIC, &ts_monotonic) < 0) {
 		err = -errno;
-		error("Failed to get CLOCK_MONOTONIC_RAW: %s", strerror(errno));
+		error("Failed to get CLOCK_MONOTONIC: %s", strerror(errno));
 		goto out;
 	}
 	ts_monotonic.tv_nsec = 0;
