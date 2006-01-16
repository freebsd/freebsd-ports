--- ./src/ccsp-1.6/common/rtsmain.c.orig	Mon Oct 24 01:10:31 2005
+++ ./src/ccsp-1.6/common/rtsmain.c	Sun Jan 15 13:56:15 2006
@@ -256,6 +256,9 @@
 		if (!fp) {
 			fp = fopen ("/etc/kroc_clock", "r");
 		}
+		if (!fp) {
+			fp = fopen ("%%PREFIX%%/etc/kroc_clock", "r");
+		}
 		if (fp) {
 			if (fscanf (fp, "%lf", &cpumhz) != 1) {
 				fprintf (stderr, "KRoC: error reading clock speed\n");
@@ -266,7 +269,7 @@
 			fp = fopen("/proc/cpuinfo", "r");
 
 			if (!fp) {
-				fprintf (stderr, "KRoC: unable to find clock file (.kroc_clock, /etc/kroc_clock or /proc/cpuinfo)\n");
+				fprintf (stderr, "KRoC: unable to find clock file (.kroc_clock, /etc/kroc_clock, %%PREFIX%%/etc/kroc_clock or /proc/cpuinfo)\n");
 				restore_tty_state ();
 				exit (1);
 			}
