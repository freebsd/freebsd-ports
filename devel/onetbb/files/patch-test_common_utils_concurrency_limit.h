Avoid dereferencing a NULL pointer

Makes the following test output cleaner:

63 - test_hw_concurrency (ILLEGAL)
(changed to)
63 - test_hw_concurrency (Subprocess aborted)

and adds the following message:

test/common/utils_concurrency_limit.h:380, assertion !cpuset_indices.empty(): Empty cpuset returned

A call to get_cpuset_indices() currently always fails on FreeBSD (not implemented).

--- test/common/utils_concurrency_limit.h.orig	2026-01-22 11:53:36 UTC
+++ test/common/utils_concurrency_limit.h
@@ -377,6 +377,7 @@ int limit_number_of_threads( int max_threads ) {
 
     ASSERT(max_threads <= int(sizeof(mask_t) * CHAR_BIT), "The mask size is not enough to set the requested number of threads.");
     std::vector<int> cpuset_indices = get_cpuset_indices();
+    ASSERT(!cpuset_indices.empty(), "Empty cpuset returned.");
 
     for (int i = 0; i < max_threads; ++i) {
         CPU_SET(cpuset_indices[i], &new_mask);
