--- pdf/font_table_linux.cc.orig	2022-05-11 07:16:54 UTC
+++ pdf/font_table_linux.cc
@@ -5,6 +5,7 @@
 #include "pdf/font_table_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <algorithm>
 #include <limits>
