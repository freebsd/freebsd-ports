--- libevmasm/Assembly.cpp.orig	2022-03-24 17:16:26 UTC
+++ libevmasm/Assembly.cpp
@@ -48,6 +48,8 @@ using namespace solidity::evmasm;
 using namespace solidity::langutil;
 using namespace solidity::util;
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 AssemblyItem const& Assembly::append(AssemblyItem _i)
 {
 	assertThrow(m_deposit >= 0, AssemblyException, "Stack underflow.");
