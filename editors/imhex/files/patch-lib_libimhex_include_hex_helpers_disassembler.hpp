--- lib/libimhex/include/hex/helpers/disassembler.hpp.orig	2022-01-31 13:32:21 UTC
+++ lib/libimhex/include/hex/helpers/disassembler.hpp
@@ -1,10 +1,7 @@
 #pragma once
 
-#if __has_include(<capstone/capstone.h>)
-    #include <capstone/capstone.h>
-#else
-    #include <capstone.h>
-#endif
+#include <capstone.h>
+
 #include <hex.hpp>
 
 namespace hex {
