--- src/classes/visioExporter.cc.orig
+++ src/classes/visioExporter.cc
@@ -1,4 +1,5 @@
 #include "visioExporter.h"
+#include <cstdlib>
 
 
 visioExporter::visioExporter(char *what_file, nodes *what_nodes) {
