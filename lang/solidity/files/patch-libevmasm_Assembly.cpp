--- libevmasm/Assembly.cpp.orig	2024-05-21 09:44:13 UTC
+++ libevmasm/Assembly.cpp
@@ -54,6 +54,8 @@ std::map<std::string, std::shared_ptr<std::string cons
 
 std::map<std::string, std::shared_ptr<std::string const>> Assembly::s_sharedSourceNames;
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 AssemblyItem const& Assembly::append(AssemblyItem _i)
 {
 	assertThrow(m_deposit >= 0, AssemblyException, "Stack underflow.");
