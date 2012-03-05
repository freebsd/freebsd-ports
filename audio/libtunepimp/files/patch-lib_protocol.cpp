--- lib/protocol.cpp.orig	2010-06-07 10:47:20.653619576 +0300
+++ lib/protocol.cpp	2010-06-07 10:47:55.249722982 +0300
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
 
