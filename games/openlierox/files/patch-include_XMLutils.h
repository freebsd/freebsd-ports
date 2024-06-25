--- include/XMLutils.h.orig	2018-01-30 13:49:55 UTC
+++ include/XMLutils.h
@@ -17,6 +17,7 @@
 
 #include <string>
 #include <libxml/xmlmemory.h>
+#include <libxml/tree.h>
 #include "Color.h"
 
 int xmlGetInt(xmlNodePtr node, const std::string& name, int def = 0);
