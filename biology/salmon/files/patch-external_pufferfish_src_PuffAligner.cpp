--- external/pufferfish/src/PuffAligner.cpp.orig	2023-06-26 19:34:50 UTC
+++ external/pufferfish/src/PuffAligner.cpp
@@ -1,7 +1,10 @@
 #include "nonstd/string_view.hpp"
 #include "PuffAligner.hpp"
 #include "Util.hpp"
-#include "libdivide/libdivide.h"
+// Bundled libdivide causes build failures with clang19
+// Use FreeBSD libdivde port instead
+// #include "libdivide/libdivide.h"
+#include <libdivide.h>
 
 std::string extractReadSeq(const std::string& readSeq, uint32_t rstart, uint32_t rend, bool isFw) {
     std::string subseq = readSeq.substr(rstart, rend - rstart);
