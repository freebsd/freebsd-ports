--- src/logging_unittest.cc.orig	2015-03-11 04:02:27 UTC
+++ src/logging_unittest.cc
@@ -78,6 +78,7 @@ using GOOGLE_NAMESPACE::glog_testing::Sc
 #endif
 
 using namespace std;
+using namespace gflags;
 using namespace GOOGLE_NAMESPACE;
 
 // Some non-advertised functions that we want to test or use.
@@ -239,9 +240,9 @@ int main(int argc, char **argv) {
 }
 
 void TestLogging(bool check_counts) {
-  int64 base_num_infos   = LogMessage::num_messages(GLOG_INFO);
-  int64 base_num_warning = LogMessage::num_messages(GLOG_WARNING);
-  int64 base_num_errors  = LogMessage::num_messages(GLOG_ERROR);
+  gflags::int64 base_num_infos   = LogMessage::num_messages(GLOG_INFO);
+  gflags::int64 base_num_warning = LogMessage::num_messages(GLOG_WARNING);
+  gflags::int64 base_num_errors  = LogMessage::num_messages(GLOG_ERROR);
 
   LOG(INFO) << string("foo ") << "bar " << 10 << ' ' << 3.4;
   for ( int i = 0; i < 10; ++i ) {
@@ -564,8 +565,8 @@ void TestDCHECK() {
   DCHECK_GT(2, 1);
   DCHECK_LT(1, 2);
 
-  auto_ptr<int64> sptr(new int64);
-  int64* ptr = DCHECK_NOTNULL(sptr.get());
+  auto_ptr<gflags::int64> sptr(new gflags::int64);
+  gflags::int64* ptr = DCHECK_NOTNULL(sptr.get());
   CHECK_EQ(ptr, sptr.get());
 }
 
@@ -594,14 +595,14 @@ TEST(DeathSTREQ, logging) {
 }
 
 TEST(CheckNOTNULL, Simple) {
-  int64 t;
+  gflags::int64 t;
   void *ptr = static_cast<void *>(&t);
   void *ref = CHECK_NOTNULL(ptr);
   EXPECT_EQ(ptr, ref);
   CHECK_NOTNULL(reinterpret_cast<char *>(ptr));
   CHECK_NOTNULL(reinterpret_cast<unsigned char *>(ptr));
   CHECK_NOTNULL(reinterpret_cast<int *>(ptr));
-  CHECK_NOTNULL(reinterpret_cast<int64 *>(ptr));
+  CHECK_NOTNULL(reinterpret_cast<gflags::int64 *>(ptr));
 }
 
 TEST(DeathCheckNN, Simple) {
@@ -736,7 +737,7 @@ struct MyLogger : public base::Logger {
 
   virtual void Flush() { }
 
-  virtual uint32 LogSize() { return data.length(); }
+  virtual gflags::uint32 LogSize() { return data.length(); }
 };
 
 static void TestWrapper() {
@@ -760,23 +761,23 @@ static void TestErrno() {
   CHECK_EQ(errno, ENOENT);
 }
 
-static void TestOneTruncate(const char *path, int64 limit, int64 keep,
-                            int64 dsize, int64 ksize, int64 expect) {
+static void TestOneTruncate(const char *path, gflags::int64 limit, gflags::int64 keep,
+                            gflags::int64 dsize, gflags::int64 ksize, gflags::int64 expect) {
   int fd;
   CHECK_ERR(fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0600));
 
   const char *discardstr = "DISCARDME!", *keepstr = "KEEPME!";
 
   // Fill the file with the requested data; first discard data, then kept data
-  int64 written = 0;
+  gflags::int64 written = 0;
   while (written < dsize) {
-    int bytes = min<int64>(dsize - written, strlen(discardstr));
+    int bytes = min<gflags::int64>(dsize - written, strlen(discardstr));
     CHECK_ERR(write(fd, discardstr, bytes));
     written += bytes;
   }
   written = 0;
   while (written < ksize) {
-    int bytes = min<int64>(ksize - written, strlen(keepstr));
+    int bytes = min<gflags::int64>(ksize - written, strlen(keepstr));
     CHECK_ERR(write(fd, keepstr, bytes));
     written += bytes;
   }
@@ -796,9 +797,9 @@ static void TestOneTruncate(const char *
   CHECK_ERR(read(fd, buf, buf_size));
 
   const char *p = buf;
-  int64 checked = 0;
+  gflags::int64 checked = 0;
   while (checked < expect) {
-    int bytes = min<int64>(expect - checked, strlen(keepstr));
+    int bytes = min<gflags::int64>(expect - checked, strlen(keepstr));
     CHECK(!memcmp(p, keepstr, bytes));
     checked += bytes;
   }
