--- storage/innobase/log/log0recv.cc.orig	2023-01-30 20:34:34.000000000 +0700
+++ storage/innobase/log/log0recv.cc	2023-03-10 12:08:29.586971000 +0700
@@ -3789,7 +3789,7 @@ static bool recv_scan_log_recs(log_t &log,
 #else  /* !UNIV_HOTBACKUP */
 bool meb_scan_log_recs(
 #endif /* !UNIV_HOTBACKUP */
-                               size_t *max_memory, const byte *buf, size_t len,
+                               size_t max_memory, const byte *buf, size_t len,
                                lsn_t start_lsn, lsn_t *read_upto_lsn,
                                dberr_t &err, lsn_t to_lsn) {
   const byte *log_block = buf;
@@ -4066,7 +4066,7 @@ bool meb_scan_log_recs(
     recv_parse_log_recs();
 
 #ifndef UNIV_HOTBACKUP
-    if (recv_heap_used() > *max_memory) {
+    if (recv_heap_used() > max_memory) {
       recv_apply_hashed_log_recs(log, false);
     }
 #endif /* !UNIV_HOTBACKUP */
@@ -4254,7 +4254,7 @@ static dberr_t recv_recovery_begin(log_t &log, const l
 
     dberr_t err;
 
-    finished = recv_scan_log_recs(log, &max_mem, log.buf, end_lsn - start_lsn,
+    finished = recv_scan_log_recs(log, max_mem, log.buf, end_lsn - start_lsn,
                                   start_lsn, &log.m_scanned_lsn, err, to_lsn);
 
     if (err != DB_SUCCESS) {
