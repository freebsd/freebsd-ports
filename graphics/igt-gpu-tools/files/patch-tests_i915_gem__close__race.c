--- tests/i915/gem_close_race.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_close_race.c
@@ -53,6 +53,10 @@
 #define BLT_WRITE_ALPHA		(1<<21)
 #define BLT_WRITE_RGB		(1<<20)
 
+#ifdef __FreeBSD__
+#define	gettid()		getpid()
+#endif
+
 IGT_TEST_DESCRIPTION("Test try to race gem_close against workload submission.");
 
 static uint32_t devid;
@@ -61,7 +65,9 @@ static uint64_t data_addr;
 static uint64_t exec_addr;
 static uint64_t data_addr;
 
+#ifdef __linux__
 #define sigev_notify_thread_id _sigev_un._tid
+#endif
 
 static void selfcopy(int fd, uint32_t ctx, uint32_t handle, int loops)
 {
