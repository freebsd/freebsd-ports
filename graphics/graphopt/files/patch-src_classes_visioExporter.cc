--- src/classes/visioExporter.cc.orig	2003-04-16 02:55:39 UTC
+++ src/classes/visioExporter.cc
@@ -1,4 +1,6 @@
 #include "visioExporter.h"
+#include <cstdlib>
+#include <cstring>
 
 
 visioExporter::visioExporter(char *what_file, nodes *what_nodes) {
