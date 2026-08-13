--- modules/util/upgrade_checker/upgrade_check_options.cc.orig	2026-01-26 17:15:26 UTC
+++ modules/util/upgrade_checker/upgrade_check_options.cc
@@ -137,13 +137,12 @@ void Upgrade_check_options::verify_options() {
         "Check timeout must be non-zero, positive value");
   }
   constexpr auto max_seconds =
-      std::chrono::duration_cast<std::chrono::seconds, int64_t>(
+      std::chrono::duration_cast<std::chrono::seconds, long long>(
           std::chrono::steady_clock::duration::max())
           .count();
   if (check_timeout.has_value() && *check_timeout > max_seconds) {
     throw std::invalid_argument(shcore::str_format(
-        "Check timeout value is bigger than supported value %" PRId64,
-        max_seconds));
+        "Check timeout value is bigger than supported value"));
   }
 }
 
