--- components/password_manager/core/browser/login_database_unittest.cc.orig	2022-11-30 08:12:58 UTC
+++ components/password_manager/core/browser/login_database_unittest.cc
@@ -2093,7 +2093,7 @@ TEST_F(LoginDatabaseUndecryptableLoginsTest, DeleteUnd
   base::HistogramTester histogram_tester;
   ASSERT_TRUE(db.Init());
 
-#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
   // Make sure that we can't get any logins when database is corrupted.
   // Disabling the checks in chromecast because encryption is unavailable.
   std::vector<std::unique_ptr<PasswordForm>> result;
@@ -2119,7 +2119,7 @@ TEST_F(LoginDatabaseUndecryptableLoginsTest, DeleteUnd
 #endif
 
 // Check histograms.
-#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
   histogram_tester.ExpectUniqueSample("PasswordManager.CleanedUpPasswords", 2,
                                       1);
   histogram_tester.ExpectUniqueSample(
@@ -2171,7 +2171,7 @@ TEST_F(LoginDatabaseUndecryptableLoginsTest, KeychainL
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Test getting auto sign in logins when there are undecryptable ones
 TEST_F(LoginDatabaseUndecryptableLoginsTest, GetAutoSignInLogins) {
   PrimaryKeyToFormMap key_to_form_map;
