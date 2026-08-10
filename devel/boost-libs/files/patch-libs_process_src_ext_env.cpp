--- libs/process/src/ext/env.cpp.orig	2026-04-15 14:38:59 UTC
+++ libs/process/src/ext/env.cpp
@@ -127,7 +127,7 @@ native_env_iterator find_end(native_env_iterator nh)
 }
 native_env_iterator find_end(native_env_iterator nh)
 {
-    while (*nh != EOF)
+    while (*nh != (char) EOF)
         nh ++;
     return nh ;
 }
@@ -318,7 +318,7 @@ env_view env(boost::process::v2::pid_type pid, error_c
 
     int f = ::open(("/proc/" + std::to_string(pid) + "/environ").c_str(), O_RDONLY);
 
-    while (!procargs || procargs.get()[size - 1] != EOF)
+    while (!procargs || procargs.get()[size - 1] != (char) EOF)
     {
         std::unique_ptr<char, detail::ext::native_env_handle_deleter> buf{new char[size + 4096]};
         if (size > 0)
