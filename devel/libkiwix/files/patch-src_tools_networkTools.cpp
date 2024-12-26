--- src/tools/networkTools.cpp.orig	2024-12-26 02:42:25 UTC
+++ src/tools/networkTools.cpp
@@ -27,6 +27,7 @@
 #include <string.h>
 
 #include <curl/curl.h>
+#include <netinet/in.h>
 
 #include <sstream>
 #include <iostream>
