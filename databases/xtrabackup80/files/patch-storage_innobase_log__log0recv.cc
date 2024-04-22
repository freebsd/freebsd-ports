--- storage/innobase/log/log0recv.cc.orig	2023-11-24 13:33:10.000000000 +0300
+++ storage/innobase/log/log0recv.cc	2024-02-16 15:16:49.528584000 +0300
@@ -3702,7 +3702,7 @@
 #else  /* !UNIV_HOTBACKUP */
 bool meb_scan_log_recs(
 #endif /* !UNIV_HOTBACKUP */
-                               size_t *max_memory, const byte *buf, size_t len,
+                               size_t max_memory, const byte *buf, size_t len,
                                lsn_t start_lsn, lsn_t *read_upto_lsn,
                                lsn_t to_lsn) {
   const byte *log_block = buf;
@@ -3975,7 +3975,7 @@
     recv_parse_log_recs();
 
 #ifndef UNIV_HOTBACKUP
-    if (recv_heap_used() > *max_memory) {
+    if (recv_heap_used() > max_memory) {
       recv_apply_hashed_log_recs(log, false);
     }
 #endif /* !UNIV_HOTBACKUP */
@@ -4161,7 +4161,7 @@
       break;
     }
 
-    finished = recv_scan_log_recs(log, &max_mem, log.buf, end_lsn - start_lsn,
+    finished = recv_scan_log_recs(log, max_mem, log.buf, end_lsn - start_lsn,
                                   start_lsn, &log.m_scanned_lsn, to_lsn);
 
     start_lsn = end_lsn;
