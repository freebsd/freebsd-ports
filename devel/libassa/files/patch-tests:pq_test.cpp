--- tests/pq_test.cpp.orig	Thu Jan 29 08:39:07 2004
+++ tests/pq_test.cpp	Thu Jan 29 08:40:48 2004
@@ -23,10 +23,6 @@
 #include <iostream>
 using namespace std;
 
-#include <getopt.h>
-extern char *optarg;
-extern int optind, opterr, optopt;
-
 // ASSA
 #include "assa/PriorityQueue.h"
 using namespace ASSA;
