--- components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2024-06-18 21:43:29 UTC
+++ components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -149,7 +149,7 @@ LoginsResultOrError LoginDatabaseAsyncHelper::FillMatc
     std::vector<PasswordForm> matched_forms;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_forms)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return PasswordStoreBackendError(
           OSCrypt::IsEncryptionAvailable()
               ? PasswordStoreBackendErrorType::kUncategorized
