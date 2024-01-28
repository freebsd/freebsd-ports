--- subprojects/rizin-shell-parser/src/parser.c.orig	2023-10-17 10:11:38 UTC
+++ subprojects/rizin-shell-parser/src/parser.c
@@ -1,4 +1,4 @@
-#include <tree_sitter/parser.h>
+#include "tree_sitter/parser.h"
 
 #if defined(__GNUC__) || defined(__clang__)
 #pragma GCC diagnostic push
