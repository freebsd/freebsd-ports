--- tests/test-abicompat.cc.orig	2025-06-12 23:47:55 UTC
+++ tests/test-abicompat.cc
@@ -22,6 +22,7 @@
 #include <fstream>
 #include <iostream>
 #include <cstdlib>
+#include <sys/wait.h>
 #include "abg-tools-utils.h"
 #include "test-utils.h"
 
