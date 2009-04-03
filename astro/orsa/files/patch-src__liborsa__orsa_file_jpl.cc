--- src/liborsa/orsa_file_jpl.cc.orig	2005-01-05 11:25:06.000000000 +0900
+++ src/liborsa/orsa_file_jpl.cc	2009-04-02 13:48:37.000000000 +0900
@@ -27,6 +27,7 @@
 #include "orsa_secure_math.h"
 
 #include <cstdio>
+#include <cstring>
 
 #include "sdncal.h"
 #include "jpleph.h"
