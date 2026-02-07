--- db/db_test_util.cc.orig	2023-02-19 21:44:55 UTC
+++ db/db_test_util.cc
@@ -102,9 +102,11 @@ DBTestBase::DBTestBase(const std::string path, bool en
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
@@ -338,6 +340,7 @@ Options DBTestBase::GetOptions(
   Options options = default_options;
   BlockBasedTableOptions table_options;
   bool set_block_based_table_factory = true;
+#ifndef NDEBUG
 #if !defined(OS_MACOSX) && !defined(OS_WIN) && !defined(OS_SOLARIS) && \
     !defined(OS_AIX)
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->ClearCallBack(
@@ -345,6 +348,7 @@ Options DBTestBase::GetOptions(
   ROCKSDB_NAMESPACE::SyncPoint::GetInstance()->ClearCallBack(
       "NewWritableFile:O_DIRECT");
 #endif
+#endif
   // kMustFreeHeapAllocations -> indicates ASAN build
   if (kMustFreeHeapAllocations && !options_override.full_block_cache) {
     // Detecting block cache use-after-free is normally difficult in unit
@@ -409,7 +413,9 @@ Options DBTestBase::GetOptions(
       options.use_direct_reads = true;
       options.use_direct_io_for_flush_and_compaction = true;
       options.compaction_readahead_size = 2 * 1024 * 1024;
+#ifndef NDEBUG
       SetupSyncPointsToMockDirectIO();
+#endif
       break;
     }
     case kMergePut:
@@ -1141,6 +1147,7 @@ std::string DBTestBase::FilesPerLevel(int cf) {
 }
 
 
+#ifndef NDEBUG
 std::vector<uint64_t> DBTestBase::GetBlobFileNumbers() {
   VersionSet* const versions = dbfull()->GetVersionSet();
   assert(versions);
@@ -1166,6 +1173,7 @@ std::vector<uint64_t> DBTestBase::GetBlobFileNumbers()
 
   return result;
 }
+#endif
 
 size_t DBTestBase::CountFiles() {
   size_t count = 0;
@@ -1248,6 +1256,7 @@ void DBTestBase::FillLevels(const std::string& smalles
 }
 
 void DBTestBase::MoveFilesToLevel(int level, int cf) {
+#ifndef NDEBUG
   for (int l = 0; l < level; ++l) {
     if (cf > 0) {
       EXPECT_OK(dbfull()->TEST_CompactRange(l, nullptr, nullptr, handles_[cf]));
@@ -1255,12 +1264,15 @@ void DBTestBase::MoveFilesToLevel(int level, int cf) {
       EXPECT_OK(dbfull()->TEST_CompactRange(l, nullptr, nullptr));
     }
   }
+#endif
 }
 
 void DBTestBase::DumpFileCounts(const char* label) {
   fprintf(stderr, "---\n%s:\n", label);
+#ifndef NDEBUG
   fprintf(stderr, "maxoverlap: %" PRIu64 "\n",
           dbfull()->TEST_MaxNextLevelOverlappingBytes());
+#endif
   for (int level = 0; level < db_->NumberLevels(); level++) {
     int num = NumTableFilesAtLevel(level);
     if (num > 0) {
@@ -1302,10 +1314,12 @@ void DBTestBase::GenerateNewFile(int cf, Random* rnd, 
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
@@ -1314,10 +1328,12 @@ void DBTestBase::GenerateNewFile(Random* rnd, int* key
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
@@ -1327,10 +1343,12 @@ void DBTestBase::GenerateNewRandomFile(Random* rnd, bo
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
