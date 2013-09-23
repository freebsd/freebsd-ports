--- utils/malloc.cpp.orig	2011-02-24 15:12:15.000000000 +0300
+++ utils/malloc.cpp	2013-09-24 00:18:58.433519194 +0400
@@ -18,6 +18,7 @@
 #include <cstdlib>
 #include <stxxl/bits/verbose.h>
 
+#include <unistd.h>
 
 void print_malloc_stats()
 {
