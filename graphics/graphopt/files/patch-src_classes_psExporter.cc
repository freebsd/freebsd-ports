--- src/classes/psExporter.cc.intermediate	2015-09-20 01:43:24 UTC
+++ src/classes/psExporter.cc
@@ -1,6 +1,6 @@
 #include "psExporter.h"
 #include <cstdlib>
-
+#include <cstring>
 
 psExporter::psExporter(char *what_file, nodes *what_nodes) {
    filename = strdup(what_file);
