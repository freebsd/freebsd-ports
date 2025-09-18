--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2025-08-26 20:49:50 UTC
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2305,7 +2305,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCurrent,
                                           testing::Bool()));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
