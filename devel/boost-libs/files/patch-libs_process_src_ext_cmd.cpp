--- libs/process/src/ext/cmd.cpp.orig	2026-04-15 14:38:59 UTC
+++ libs/process/src/ext/cmd.cpp
@@ -219,7 +219,7 @@ shell cmd(boost::process::v2::pid_type pid, error_code
     procargs.resize(4096);
     int f = ::open(("/proc/" + std::to_string(pid) + "/cmdline").c_str(), O_RDONLY);
 
-    while (procargs.back() != EOF)
+    while (procargs.back() != (char) EOF)
     {
         auto r = ::read(f, &*(procargs.end() - 4096), 4096);
         if (r < 0)
@@ -237,7 +237,7 @@ shell cmd(boost::process::v2::pid_type pid, error_code
     }
     ::close(f);
 
-    if (procargs.back() == EOF)
+    if (procargs.back() == (char) EOF)
         procargs.pop_back();
 
     auto argc = std::count(procargs.begin(), procargs.end(), '\0');
