--- src/utils/Glue.cpp.orig	2006-09-15 05:40:18.000000000 +0900
+++ src/utils/Glue.cpp	2012-10-03 00:23:38.000000000 +0900
@@ -6,6 +6,7 @@
 #include <fstream>
 #include <iostream>
 #include <algorithm>
+#include <cstring>
 
 #define NUCLEOTIDE_MATRIX_FILE "nucmatrix.txt"
 #define MAX_LINE_LENGTH 1024
