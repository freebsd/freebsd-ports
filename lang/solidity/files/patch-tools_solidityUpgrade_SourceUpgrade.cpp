- workaround for https://github.com/ethereum/solidity/issues/13091

--- tools/solidityUpgrade/SourceUpgrade.cpp.orig	2022-06-02 02:23:26 UTC
+++ tools/solidityUpgrade/SourceUpgrade.cpp
@@ -34,6 +34,8 @@
 	#include <unistd.h>
 #endif
 
+#include <fstream>
+
 
 namespace po = boost::program_options;
 namespace fs = boost::filesystem;
