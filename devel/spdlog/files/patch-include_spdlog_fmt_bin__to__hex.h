--- include/spdlog/fmt/bin_to_hex.h.orig	2021-06-24 14:01:22 UTC
+++ include/spdlog/fmt/bin_to_hex.h
@@ -209,7 +209,7 @@ struct formatter<spdlog::details::dump_info<T>>
 
         if (put_positions)
         {
-            fmt::format_to(inserter, "{:<04X}: ", pos);
+            fmt::format_to(inserter, "{:04X}: ", pos);
         }
     }
 };
