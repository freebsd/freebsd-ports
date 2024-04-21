FreeBSD defines crypt_r() via <unistd.h>.

--- lib/impersonation.cpp.orig	2023-06-28 13:00:47 UTC
+++ lib/impersonation.cpp
@@ -8,8 +8,6 @@
 #include <tuple>
 
 #if FZ_UNIX
-#include <crypt.h>
-#include <shadow.h>
 #endif
 #include <grp.h>
 #include <limits.h>
@@ -98,43 +96,7 @@ std::optional<gid_t> get_group(native_string const& gn
 	return {};
 }
 
-#if FZ_UNIX
-struct shadow_holder {
-	shadow_holder() = default;
-	shadow_holder(shadow_holder const&) = delete;
-	shadow_holder(shadow_holder &&) = default;
-
-	shadow_holder& operator=(shadow_holder const&) = delete;
-	shadow_holder& operator=(shadow_holder &&) = default;
-
-	~shadow_holder() noexcept = default;
-
-	struct spwd* shadow_{};
-
-	struct spwd shadow_buffer_;
-	buffer buf_{};
-};
-
-shadow_holder get_shadow(native_string const& username)
-{
-	shadow_holder ret;
-
-	size_t s = 1024;
-	int res{};
-	do {
-		s *= 2;
-		ret.buf_.get(s);
-		res = getspnam_r(username.c_str(), &ret.shadow_buffer_, reinterpret_cast<char*>(ret.buf_.get(s)), s, &ret.shadow_);
-	} while (res == ERANGE);
-
-	if (res) {
-		ret.shadow_ = nullptr;
-	}
-
-	return ret;
 }
-#endif
-}
 
 class impersonation_token_impl final
 {
@@ -191,14 +153,7 @@ bool check_auth(native_string const& username, native_
 bool check_auth(native_string const& username, native_string const& password)
 {
 #if FZ_UNIX
-	auto shadow = get_shadow(username);
-	if (shadow.shadow_) {
-		struct crypt_data data{};
-		char* encrypted = crypt_r(password.c_str(), shadow.shadow_->sp_pwdp, &data);
-		if (encrypted && !strcmp(encrypted, shadow.shadow_->sp_pwdp)) {
-			return true;
-		}
-	}
+	return false; // FreeBSD does not have shadow.h support
 #elif FZ_MAC
 	bool ret{};
 
