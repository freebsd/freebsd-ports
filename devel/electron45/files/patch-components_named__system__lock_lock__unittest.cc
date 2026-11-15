--- components/named_system_lock/lock_unittest.cc.orig	2026-06-23 23:37:18 UTC
+++ components/named_system_lock/lock_unittest.cc
@@ -18,7 +18,7 @@
 #include "build/build_config.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <fcntl.h>
 #include <sys/mman.h>
 
@@ -44,7 +44,7 @@ class NamedSystemLockTest : public ::testing::Test {
   const std::string lock_name_ = base::UnguessableToken::Create().ToString();
 
   std::unique_ptr<ScopedLock> CreateLock() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     return ScopedLock::Create(lock_name_, base::Seconds(0));
 #else
     SECURITY_ATTRIBUTES sa = {sizeof(SECURITY_ATTRIBUTES), nullptr, FALSE};
@@ -94,7 +94,7 @@ TEST_F(NamedSystemLockTest, TryLockInThreadSuccess) {
   EXPECT_TRUE(CreateLock());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST_F(NamedSystemLockTest, SharedMemoryWrongPermissions) {
   // Create a shared memory region with overpermissive perms.
   int shm_fd = shm_open(lock_name_.c_str(), O_RDWR | O_CREAT | O_EXCL,
