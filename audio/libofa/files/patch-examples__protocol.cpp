--- ./examples/protocol.cpp.orig	2011-03-18 11:01:22.000000000 -0400
+++ ./examples/protocol.cpp	2011-03-18 11:01:22.000000000 -0400
@@ -8,11 +8,11 @@
 -------------------------------------------------------------------*/
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <string>
 #include <map>
 #include <expat.h>
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 
 using namespace std;
