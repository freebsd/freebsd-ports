--- leveldb_object.cc.orig	2016-12-27 23:03:15 UTC
+++ leveldb_object.cc
@@ -901,9 +901,8 @@ static int PyLevelDB_init(PyLevelDB* sel
 	int block_size = 4096;
 	int max_open_files = 1000;
 	int block_restart_interval = 16;
-  int max_file_size = 2 << 20;
 	const char* kwargs[] = {"filename", "create_if_missing", "error_if_exists", "paranoid_checks", "write_buffer_size",
-    "block_size", "max_open_files", "block_restart_interval", "block_cache_size", "max_file_size", "comparator", 0};
+    "block_size", "max_open_files", "block_restart_interval", "block_cache_size", "comparator", 0};
 
 	PyObject* comparator = 0;
 
@@ -917,7 +916,6 @@ static int PyLevelDB_init(PyLevelDB* sel
 		&max_open_files,
 		&block_restart_interval,
 		&block_cache_size,
-		&max_file_size,
 		&comparator))
 		return -1;
 
@@ -963,7 +961,6 @@ static int PyLevelDB_init(PyLevelDB* sel
 	self->_options->block_restart_interval = block_restart_interval;
 	self->_options->compression = leveldb::kSnappyCompression;
 	self->_options->block_cache = self->_cache;
-	self->_options->max_file_size = max_file_size;
 	self->_options->comparator = self->_comparator;
 	leveldb::Status status;
 
