--- subprojects/rizin-shell-parser/src/scanner.c.orig	2023-10-17 10:11:38 UTC
+++ subprojects/rizin-shell-parser/src/scanner.c
@@ -1,7 +1,7 @@
 // SPDX-FileCopyrightText: 2020 ret2libc <sirmy15@gmail.com>
 // SPDX-License-Identifier: LGPL-3.0-only
 
-#include <tree_sitter/parser.h>
+#include "tree_sitter/parser.h"
 #include <ctype.h>
 #include <wctype.h>
 #include <stdio.h>
