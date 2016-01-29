--- src/classes/optFileWriter.cc.orig	2003-01-25 05:17:43 UTC
+++ src/classes/optFileWriter.cc
@@ -1,4 +1,6 @@
 #include "optFileWriter.h"
+#include <cstdlib>
+#include <cstring>
 
 
 optFileWriter::optFileWriter(char *what_file, nodes *what_nodes) {
