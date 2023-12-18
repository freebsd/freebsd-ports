--- storage/innobase/log/log0recv.cc.orig	2023-12-17 10:36:48 UTC
+++ storage/innobase/log/log0recv.cc
@@ -3695,7 +3695,7 @@ static void recv_recovery_begin(log_t &log, const lsn_
       than number of concurrent IOs we want to sustain. We should also keep in
       mind that the limit for the deltas hashmap is not strictly enforced and
       this number includes the not-well specified safety margin. */
-      size_t{256} * srv_buf_pool_instances);
+      static_cast<unsigned int>(size_t{256} * srv_buf_pool_instances));
   const size_t delta_hashmap_max_mem =
       UNIV_PAGE_SIZE * (buf_pool_get_n_pages() - pages_to_be_kept_free);

