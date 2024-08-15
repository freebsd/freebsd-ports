--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2024-06-18 21:43:29 UTC
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2132,7 +2132,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCurrent,
                          LoginDatabaseMigrationTestBroken,
                          testing::Values(1, 2, 3, 24));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
