--- libevmasm/Assembly.cpp.orig	2023-07-19 09:24:46 UTC
+++ libevmasm/Assembly.cpp
@@ -47,6 +47,8 @@ using namespace solidity::evmasm;
 using namespace solidity::langutil;
 using namespace solidity::util;
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 AssemblyItem const& Assembly::append(AssemblyItem _i)
 {
 	assertThrow(m_deposit >= 0, AssemblyException, "Stack underflow.");
