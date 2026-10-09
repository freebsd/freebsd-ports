-- workaround for the surrealdb-rocksb* crates expecting a bleading
-- edge RocksDB while the port only has a current-ish version

--- surrealdb/core/src/kvs/rocksdb/memory_manager.rs.orig	2026-10-09 00:56:52 UTC
+++ surrealdb/core/src/kvs/rocksdb/memory_manager.rs
@@ -139,14 +139,14 @@ impl MemoryManager {
 		info!(target: TARGET, "Block size for partitioned metadata: 4096 B");
 		block.set_metadata_block_size(4096);
 		// Set the initial size for implicit iterator auto-readahead
-		info!(target: TARGET, "Initial auto-readahead size: {}", config.initial_auto_readahead_size);
-		block.set_initial_auto_readahead_size(config.initial_auto_readahead_size);
+		//info!(target: TARGET, "Initial auto-readahead size: {}", config.initial_auto_readahead_size);
+		//block.set_initial_auto_readahead_size(config.initial_auto_readahead_size);
 		// Set the maximum size for implicit iterator auto-readahead
-		info!(target: TARGET, "Maximum auto-readahead size: {}", config.max_auto_readahead_size);
-		block.set_max_auto_readahead_size(config.max_auto_readahead_size);
+		//info!(target: TARGET, "Maximum auto-readahead size: {}", config.max_auto_readahead_size);
+		//block.set_max_auto_readahead_size(config.max_auto_readahead_size);
 		// Set the number of sequential file reads before triggering auto-readahead
-		info!(target: TARGET, "Number of file reads for auto-readahead: {}", config.file_reads_for_auto_readahead);
-		block.set_num_file_reads_for_auto_readahead(config.file_reads_for_auto_readahead);
+		//info!(target: TARGET, "Number of file reads for auto-readahead: {}", config.file_reads_for_auto_readahead);
+		//block.set_num_file_reads_for_auto_readahead(config.file_reads_for_auto_readahead);
 		// When the prefix extractor is enabled the SST bloom filter is
 		// keyed on table+category prefixes. `whole_key_filtering=true`
 		// additionally adds whole keys (better for point lookups, larger
