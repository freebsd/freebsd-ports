--- tinyxml/tinyxmlparser.cpp.orig
+++ tinyxml/tinyxmlparser.cpp
@@ -23,7 +23,8 @@
 
 
 #include "tinyxml.h"
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 const char* TiXmlBase::SkipWhiteSpace( const char* p )
 {
