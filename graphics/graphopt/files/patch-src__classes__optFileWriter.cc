--- src/classes/optFileWriter.cc.orig
+++ src/classes/optFileWriter.cc
@@ -1,4 +1,5 @@
 #include "optFileWriter.h"
+#include <cstdlib>
 
 
 optFileWriter::optFileWriter(char *what_file, nodes *what_nodes) {
