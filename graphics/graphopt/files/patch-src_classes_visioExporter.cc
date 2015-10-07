--- src/classes/visioExporter.cc.intermediate	2015-09-20 01:43:24 UTC
+++ src/classes/visioExporter.cc
@@ -1,5 +1,6 @@
 #include "visioExporter.h"
 #include <cstdlib>
+#include <cstring>
 
 
 visioExporter::visioExporter(char *what_file, nodes *what_nodes) {
