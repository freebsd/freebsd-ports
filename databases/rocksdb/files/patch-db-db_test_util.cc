--- db/db_test_util.cc.orig	2022-06-08 21:08:16 UTC
+++ db/db_test_util.cc
@@ -104,9 +104,11 @@ DBTestBase::DBTestBase(const std::string path, bool en
 }
 
 DBTestBase::~DBTestBase() {
+#ifndef NDEBUG
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->DisableProcessing();
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->LoadDependency({});
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->ClearAllCallBacks();
+#endif
   Close();
   Options options;
   options.db_paths.emplace_back(dbname_, 0);
@@ -356,6 +358,7 @@ Options DBTestBase::GetOptions(
   Options options = default_options;
   BlockBasedTableOptions table_options;
   bool set_block_based_table_factory = true;
+#ifndef NDEBUG
 #if !defined(OS_MACOSX) && !defined(OS_WIN) && !defined(OS_SOLARIS) && \
     !defined(OS_AIX)
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->ClearCallBack(
@@ -363,6 +366,7 @@ Options DBTestBase::GetOptions(
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->ClearCallBack(
       "NewWritableFile:O_DIRECT");
 #endif
+#endif
   // kMustFreeHeapAllocations -> indicates ASAN build
   if (kMustFreeHeapAllocations && !options_override.full_block_cache) {
     // Detecting block cache use-after-free is normally difficult in unit
@@ -428,7 +432,9 @@ Options DBTestBase::GetOptions(
         options.use_direct_reads = true;
         options.use_direct_io_for_flush_and_compaction = true;
         options.compaction_readahead_size = 2 * 1024 * 1024;
+#ifndef NDEBUG
         SetupSyncPointsToMockDirectIO();
+#endif
         break;
       }
 #endif  // ROCKSDB_LITE
@@ -1149,6 +1155,7 @@ std::string DBTestBase::FilesPerLevel(int cf) {
 
 #endif  // !ROCKSDB_LITE
 
+#ifndef NDEBUG
 std::vector<uint64_t> DBTestBase::GetBlobFileNumbers() {
   VersionSet* const versions = dbfull()->GetVersionSet();
   assert(versions);
@@ -1174,6 +1181,7 @@ std::vector<uint64_t> DBTestBase::GetBlobFileNumbers()
 
   return result;
 }
+#endif
 
 size_t DBTestBase::CountFiles() {
   size_t count = 0;
@@ -1256,6 +1264,7 @@ void DBTestBase::FillLevels(const std::string& smalles
 }
 
 void DBTestBase::MoveFilesToLevel(int level, int cf) {
+#ifndef NDEBUG
   for (int l = 0; l < level; ++l) {
     if (cf > 0) {
       EXPECT_OK(dbfull()->TEST_CompactRange(l, nullptr, nullptr, handles_[cf]));
@@ -1263,13 +1272,16 @@ void DBTestBase::MoveFilesToLevel(int level, int cf) {
       EXPECT_OK(dbfull()->TEST_CompactRange(l, nullptr, nullptr));
     }
   }
+#endif
 }
 
 #ifndef ROCKSDB_LITE
 void DBTestBase::DumpFileCounts(const char* label) {
   fprintf(stderr, "---\n%s:\n", label);
+#ifndef NDEBUG
   fprintf(stderr, "maxoverlap: %" PRIu64 "\n",
           dbfull()->TEST_MaxNextLevelOverlappingBytes());
+#endif
   for (int level = 0; level < db_->NumberLevels(); level++) {
     int num = NumTableFilesAtLevel(level);
     if (num > 0) {
@@ -1310,10 +1322,12 @@ void DBTestBase::GenerateNewFile(int cf, Random* rnd, 
     ASSERT_OK(Put(cf, Key(*key_idx), rnd->RandomString((i == 99) ? 1 : 990)));
     (*key_idx)++;
   }
+#ifndef NDEBUG
   if (!nowait) {
     ASSERT_OK(dbfull()->TEST_WaitForFlushMemTable());
     ASSERT_OK(dbfull()->TEST_WaitForCompact());
   }
+#endif
 }
 
 // this will generate non-overlapping files since it keeps increasing key_idx
@@ -1322,10 +1336,12 @@ void DBTestBase::GenerateNewFile(Random* rnd, int* key
     ASSERT_OK(Put(Key(*key_idx), rnd->RandomString((i == 99) ? 1 : 990)));
     (*key_idx)++;
   }
+#ifndef NDEBUG
   if (!nowait) {
     ASSERT_OK(dbfull()->TEST_WaitForFlushMemTable());
     ASSERT_OK(dbfull()->TEST_WaitForCompact());
   }
+#endif
 }
 
 const int DBTestBase::kNumKeysByGenerateNewRandomFile = 51;
@@ -1335,10 +1351,12 @@ void DBTestBase::GenerateNewRandomFile(Random* rnd, bo
     ASSERT_OK(Put("key" + rnd->RandomString(7), rnd->RandomString(2000)));
   }
   ASSERT_OK(Put("key" + rnd->RandomString(7), rnd->RandomString(200)));
+#ifndef NDEBUG
   if (!nowait) {
     ASSERT_OK(dbfull()->TEST_WaitForFlushMemTable());
     ASSERT_OK(dbfull()->TEST_WaitForCompact());
   }
+#endif
 }
 
 std::string DBTestBase::IterStatus(Iterator* iter) {
