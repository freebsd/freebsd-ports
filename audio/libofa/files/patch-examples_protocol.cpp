--- examples/protocol.cpp.orig	2016-07-26 15:10:24 UTC
+++ examples/protocol.cpp
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
