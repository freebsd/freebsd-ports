- workaround for https://github.com/FillZpp/sys-info-rs/issues/119

--- cargo-crates/sys-info-0.9.1/c/freebsd.c.orig	2024-10-23 06:00:50 UTC
+++ cargo-crates/sys-info-0.9.1/c/freebsd.c
@@ -28,7 +28,7 @@ const char *get_os_release(void) {
 	return (os_release);
 }
 
-uint64_t get_cpu_speed(void) {
+unsigned long get_cpu_speed(void) {
 	uint64_t tsc_freq;
 	size_t len;
 	int error;
@@ -44,7 +44,7 @@ uint64_t get_cpu_speed(void) {
 	return (tsc_freq / 1000 / 1000);
 }
 
-uint64_t get_proc_total(void) {
+unsigned long get_proc_total(void) {
 	struct kinfo_proc *kp, *kpp;
 	int mib[3], count, error;
 	size_t len;
