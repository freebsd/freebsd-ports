-- Fix VSS extension build with DuckDB 1.5.5. BoundIndex API replaced CommitDrop with
-- the pure virtual ResetStorage; rename the HNSW implementation accordingly.
-- Upstream fix: https://github.com/duckdb/duckdb-vss/commit/b1cb21ad (Bump duckdb submodule)

--- extension/vss/src/hnsw/hnsw_index.cpp.orig	2026-07-24 23:53:33 UTC
+++ extension/vss/src/hnsw/hnsw_index.cpp
@@ -407,7 +407,7 @@ void HNSWIndex::ResetMultiScan(IndexScanState &state) 
 	scan_state.row_ids.clear();
 }
 
-void HNSWIndex::CommitDrop(IndexLock &index_lock) {
+void HNSWIndex::ResetStorage(IndexLock &index_lock) {
 	// Acquire an exclusive lock to drop the index
 	auto lock = rwlock.GetExclusiveLock();
 
