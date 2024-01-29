--- chrome/test/chromedriver/capabilities.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/test/chromedriver/capabilities.cc
@@ -346,7 +346,11 @@ Status ParseMobileEmulation(const base::Value& option,
                         "'version' field of type string");
         }
 
+#if defined(__clang__) && (__clang_major__ >= 15)
         brands.emplace_back(*brand, *version);
+#else
+        brands.emplace_back() = {*brand, *version};
+#endif
       }
 
       client_hints.brands = std::move(brands);
@@ -384,7 +388,11 @@ Status ParseMobileEmulation(const base::Value& option,
                         "a 'version' field of type string");
         }
 
+#if defined(__clang__) && (__clang_major__ >= 15)
         full_version_list.emplace_back(*brand, *version);
+#else
+        full_version_list.emplace_back() = {*brand, *version};
+#endif
       }
 
       client_hints.full_version_list = std::move(full_version_list);
