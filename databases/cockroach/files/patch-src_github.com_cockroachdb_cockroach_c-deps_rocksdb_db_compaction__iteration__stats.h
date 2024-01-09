--- src/github.com/cockroachdb/cockroach/c-deps/rocksdb/db/compaction_iteration_stats.h.orig	2020-06-29 21:13:41 UTC
+++ src/github.com/cockroachdb/cockroach/c-deps/rocksdb/db/compaction_iteration_stats.h
@@ -1,3 +1,5 @@
+#include <cstdint>
+
 //  Copyright (c) 2016-present, Facebook, Inc.  All rights reserved.
 //  This source code is licensed under both the GPLv2 (found in the
 //  COPYING file in the root directory) and Apache 2.0 License
