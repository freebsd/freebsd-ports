--- libevmasm/SemanticInformation.cpp.orig	2023-07-19 09:24:46 UTC
+++ libevmasm/SemanticInformation.cpp
@@ -28,6 +28,8 @@
 using namespace solidity;
 using namespace solidity::evmasm;
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 std::vector<SemanticInformation::Operation> SemanticInformation::readWriteOperations(Instruction _instruction)
 {
 	switch (_instruction)
