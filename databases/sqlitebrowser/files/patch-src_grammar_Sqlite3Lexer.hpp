--- src/grammar/Sqlite3Lexer.hpp.orig	2018-12-19 22:04:37 UTC
+++ src/grammar/Sqlite3Lexer.hpp
@@ -7,6 +7,7 @@
 #include <antlr/InputBuffer.hpp>
 #include <antlr/BitSet.hpp>
 #include "sqlite3TokenTypes.hpp"
+#include <strings.h>
 #include <antlr/CharScanner.hpp>
 class CUSTOM_API Sqlite3Lexer : public ANTLR_USE_NAMESPACE(antlr)CharScanner, public sqlite3TokenTypes
 {
