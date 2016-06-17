--- src/classes/psExporter.cc.orig	2003-04-18 04:47:40 UTC
+++ src/classes/psExporter.cc
@@ -1,5 +1,6 @@
 #include "psExporter.h"
-
+#include <cstdlib>
+#include <cstring>
 
 psExporter::psExporter(char *what_file, nodes *what_nodes) {
    filename = strdup(what_file);
@@ -26,7 +27,7 @@ void psExporter::do_export() {
 
 void psExporter::write_headers(FILE *outfile) {
    char *line = new char[200];
-   sprintf(line, "\%!PS-Adobe-1.0\n%%%%BoundingBox: 0 0 %d %d\n%%%%DocumentFonts: Helvetica\n%%%%Pages: 1\n",
+   sprintf(line, "%%!PS-Adobe-1.0\n%%%%BoundingBox: 0 0 %d %d\n%%%%DocumentFonts: Helvetica\n%%%%Pages: 1\n",
            translatexcoord((double) biggest_x) + 2 * margin,
            translateycoord((double) biggest_y) + 2 * margin);
    fwrite(line, strlen(line), 1, outfile);
