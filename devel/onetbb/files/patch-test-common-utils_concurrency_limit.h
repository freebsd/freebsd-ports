Backport edc39b844a483b69c39c64a136c4d62342884892 and 5c5d500d4fd502baed5176a19306e70c72d9c4e4

--- test/common/utils_concurrency_limit.h.orig	2021-06-30 08:19:55 UTC
+++ test/common/utils_concurrency_limit.h
@@ -166,9 +166,10 @@ int limit_number_of_threads( int max_threads ) {
 
 #endif // __TBB_TEST_SKIP_AFFINITY
 
-#define OS_AFFINITY_SYSCALL_PRESENT ((__linux__ && !__ANDROID__) || (__FreeBSD_version >= 701000))
+#define OS_AFFINITY_SYSCALL_PRESENT (__linux__ && !__ANDROID__)
 
 #if OS_AFFINITY_SYSCALL_PRESENT
+
 void get_thread_affinity_mask(std::size_t& ncpus, std::vector<int>& free_indexes) {
     cpu_set_t* mask = nullptr;
     ncpus = sizeof(cpu_set_t) * CHAR_BIT;
