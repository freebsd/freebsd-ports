--- libsparse/sparse_read.cpp.orig	2017-06-20 10:50:27 UTC
+++ libsparse/sparse_read.cpp
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string>
+#include <string.h> // memset
 #include <unistd.h>
 
 #include <sparse/sparse.h>
