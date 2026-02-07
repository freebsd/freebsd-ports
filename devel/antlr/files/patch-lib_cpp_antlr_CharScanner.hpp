--- lib/cpp/antlr/CharScanner.hpp.orig	2018-12-19 22:22:30 UTC
+++ lib/cpp/antlr/CharScanner.hpp
@@ -31,6 +31,7 @@
 #include <antlr/InputBuffer.hpp>
 #include <antlr/BitSet.hpp>
 #include <antlr/LexerSharedInputState.hpp>
+#include <strings.h>
 
 #ifdef ANTLR_CXX_SUPPORTS_NAMESPACE
 namespace antlr {
