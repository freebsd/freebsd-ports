--- src/liborsa/orsa_file.cc.orig	2005-01-11 10:01:11.000000000 +0900
+++ src/liborsa/orsa_file.cc	2009-04-02 13:48:37.000000000 +0900
@@ -24,6 +24,8 @@
 
 #include "orsa_file.h"
 
+#include <algorithm>
+#include <cstring>
 #include <iostream>
 
 #include <ctype.h>
