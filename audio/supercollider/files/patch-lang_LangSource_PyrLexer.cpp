--- lang/LangSource/PyrLexer.cpp.orig	2024-03-15 10:40:00 UTC
+++ lang/LangSource/PyrLexer.cpp
@@ -38,7 +38,7 @@
 
 #include <boost/filesystem/path.hpp>
 #include <boost/filesystem/operations.hpp>
-#include <boost/filesystem/string_file.hpp>
+#include "string_file.hpp"
 
 #include "PyrParseNode.h"
 #include "Bison/lang11d_tab.h"
