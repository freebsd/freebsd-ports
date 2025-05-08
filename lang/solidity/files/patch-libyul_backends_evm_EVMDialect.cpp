--- libyul/backends/evm/EVMDialect.cpp.orig	2025-05-08 16:10:03 UTC
+++ libyul/backends/evm/EVMDialect.cpp
@@ -56,6 +56,8 @@ std::tuple<size_t, size_t> constexpr verbatimIndexToAr
 	return std::make_tuple(_index - numRets * EVMDialect::verbatimMaxInputSlots, numRets);
 }
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 BuiltinFunctionForEVM createEVMFunction(
 	langutil::EVMVersion _evmVersion,
 	std::string const& _name,
