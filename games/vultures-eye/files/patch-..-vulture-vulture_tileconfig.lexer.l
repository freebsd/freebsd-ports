--- ../vulture/vulture_tileconfig.lexer.l.orig	2011-04-05 02:23:52.000000000 +0800
+++ ../vulture/vulture_tileconfig.lexer.l	2020-10-01 21:55:27.849177000 +0800
@@ -7,7 +7,7 @@
 #include "vulture_types.h"
 #include "vulture_tile.h"
 #include "vulture_tileconfig.h"
-#include "vulture_tileconfig.parser.h"
+#include "vulture_tileconfig.parser.hpp"
 
 #define YY_SKIP_YYWRAP
 extern int yywrap();
