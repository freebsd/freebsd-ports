-- Fix VSS extension build with DuckDB 1.5.5. BoundIndex API replaced CommitDrop with
-- the pure virtual ResetStorage; rename the HNSW declaration accordingly.
-- Upstream fix: https://github.com/duckdb/duckdb-vss/commit/b1cb21ad (Bump duckdb submodule)

--- extension/vss/src/include/hnsw/hnsw_index.hpp.orig	2026-07-24 23:53:33 UTC
+++ extension/vss/src/include/hnsw/hnsw_index.hpp
@@ -78,8 +78,8 @@ class HNSWIndex : public BoundIndex { (public)
 	//! Called when data is appended to the index. The lock obtained from InitializeLock must be held
 	ErrorData Append(IndexLock &lock, DataChunk &entries, Vector &row_identifiers) override;
 
-	//! Deletes all data from the index. The lock obtained from InitializeLock must be held
-	void CommitDrop(IndexLock &index_lock) override;
+	//! Resets all index storage, clearing the index entirely. The lock obtained from InitializeLock must be held
+	void ResetStorage(IndexLock &index_lock) override;
 	//! Delete a chunk of entries from the index. The lock obtained from InitializeLock must be held
 	void Delete(IndexLock &lock, DataChunk &entries, Vector &row_identifiers) override;
 	//! Insert a chunk of entries into the index
