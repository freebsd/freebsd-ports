--- plugins/xml/xmlplugin.h.orig	Thu Dec  4 22:21:26 2003
+++ plugins/xml/xmlplugin.h	Fri Dec  5 14:16:02 2003
@@ -24,8 +24,8 @@
 
 #include <stdlib.h>
 #include <tree.h>
-#include <xmlmemory.h>
-#include <parser.h>
+#include <libxml/xmlmemory.h>
+#include <libxml/parser.h>
 
 class XMLDBPlugin : public LocalFileDBPlugin {
  public:
