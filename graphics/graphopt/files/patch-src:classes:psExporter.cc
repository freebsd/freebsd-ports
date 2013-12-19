--- src/classes/psExporter.cc.orig	Mon Aug  9 09:31:11 2004
+++ src/classes/psExporter.cc	Mon Aug  9 09:31:38 2004
@@ -1,4 +1,5 @@
 #include "psExporter.h"
+#include <cstdlib>
 
 
 psExporter::psExporter(char *what_file, nodes *what_nodes) {
@@ -26,7 +27,7 @@
 
 void psExporter::write_headers(FILE *outfile) {
    char *line = new char[200];
-   sprintf(line, "\%!PS-Adobe-1.0\n%%%%BoundingBox: 0 0 %d %d\n%%%%DocumentFonts: Helvetica\n%%%%Pages: 1\n",
+   sprintf(line, "%%!PS-Adobe-1.0\n%%%%BoundingBox: 0 0 %d %d\n%%%%DocumentFonts: Helvetica\n%%%%Pages: 1\n",
            translatexcoord((double) biggest_x) + 2 * margin,
            translateycoord((double) biggest_y) + 2 * margin);
    fwrite(line, strlen(line), 1, outfile);
