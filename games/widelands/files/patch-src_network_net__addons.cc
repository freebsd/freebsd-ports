--- src/network/net_addons.cc.orig	2021-06-14 09:22:20 UTC
+++ src/network/net_addons.cc
@@ -179,7 +179,7 @@ std::vector<AddOnInfo> NetAddons::refresh_remotes() {
 			const std::string name = next_word(output);
 			const std::string msg = next_word(output);
 			const std::string v = next_word(output);
-			const uint32_t t = next_number(output);
+			const std::time_t t = next_number(output);
 			info.user_comments.push_back(AddOnComment{name, msg, string_to_version(v), t});
 		}
 
