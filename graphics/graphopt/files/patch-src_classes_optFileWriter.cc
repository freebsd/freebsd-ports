--- src/classes/optFileWriter.cc.intermediate	2015-09-20 01:43:24 UTC
+++ src/classes/optFileWriter.cc
@@ -1,5 +1,6 @@
 #include "optFileWriter.h"
 #include <cstdlib>
+#include <cstring>
 
 
 optFileWriter::optFileWriter(char *what_file, nodes *what_nodes) {
