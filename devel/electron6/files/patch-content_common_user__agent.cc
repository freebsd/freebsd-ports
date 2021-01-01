--- content/common/user_agent.cc.orig	2019-09-10 11:14:02 UTC
+++ content/common/user_agent.cc
@@ -131,6 +131,14 @@ std::string BuildOSCpuInfo(bool include_android_build_
 #endif
   );  // NOLINT
 
+#if defined(OS_BSD)
+#if defined(__x86_64__)
+  base::StringAppendF(&os_cpu, "; Linux x86_64");
+#else
+  base::StringAppendF(&os_cpu, "; Linux i686");
+#endif
+#endif
+
   return os_cpu;
 }
 
