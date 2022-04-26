--- libevmasm/SemanticInformation.cpp.orig	2022-03-24 17:18:03 UTC
+++ libevmasm/SemanticInformation.cpp
@@ -29,6 +29,8 @@ using namespace std;
 using namespace solidity;
 using namespace solidity::evmasm;
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 vector<SemanticInformation::Operation> SemanticInformation::readWriteOperations(Instruction _instruction)
 {
 	switch (_instruction)
